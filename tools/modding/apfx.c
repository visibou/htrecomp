/* apfx <file.apf> <outdir> [substring]  - extract AKPF v5 entries (XMemCompress/LZX) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "mspack.h"
#include "lzx.h"
typedef struct { struct mspack_system sys; } msys;
typedef struct { unsigned char *buf; size_t size, off; } mfile;
static int m_read(struct mspack_file *f, void *b, int n){ mfile*m=(mfile*)f; size_t r=m->size-m->off; if((size_t)n<r)r=n; memcpy(b,m->buf+m->off,r); m->off+=r; return (int)r; }
static int m_write(struct mspack_file *f, void *b, int n){ mfile*m=(mfile*)f; size_t r=m->size-m->off; if((size_t)n<r)r=n; memcpy(m->buf+m->off,b,r); m->off+=r; return (int)r; }
static void* m_alloc(struct mspack_system*s,size_t n){ return calloc(n,1);} static void m_free(void*p){free(p);}
static void m_copy(void*s,void*d,size_t n){ memcpy(d,s,n);}
static unsigned be32(const unsigned char*p){return (p[0]<<24)|(p[1]<<16)|(p[2]<<8)|p[3];}
static unsigned be16(const unsigned char*p){return (p[0]<<8)|p[1];}
int unpack(const unsigned char*src,size_t clen,unsigned char*dst,size_t ulen,int wbits){
  /* strip XMemCompress frame headers, concatenate LZX blocks */
  unsigned char*cat=malloc(clen+16); size_t cl=0,p=0;
  while(p+2<=clen){ unsigned cs;
    if(src[p]==0xFF){ if(p+5>clen)break; cs=be16(src+p+3); p+=5; } else { cs=be16(src+p); p+=2; }
    if(cs==0||p+cs>clen)break; memcpy(cat+cl,src+p,cs); cl+=cs; p+=cs; }
  struct mspack_system sys={0}; sys.read=m_read; sys.write=m_write; sys.alloc=m_alloc; sys.free=m_free; sys.copy=m_copy;
  mfile in={cat,cl,0}, out={dst,ulen,0};
  struct lzxd_stream*z=lzxd_init(&sys,(struct mspack_file*)&in,(struct mspack_file*)&out,wbits,0,0x8000,(off_t)ulen,0);
  int rc=z?lzxd_decompress(z,(off_t)ulen):-1; if(z)lzxd_free(z); free(cat); return rc;
}
static void mkdirs(char*path){ for(char*q=path+1;*q;q++){ if(*q=='/'||*q==92){ char c=*q;*q=0;_mkdir(path);*q=c; } } }
int main(int argc,char**argv){
  if(argc<3){fprintf(stderr,"usage\n");return 2;}
  FILE*f=fopen(argv[1],"rb"); if(!f)return 1; fseek(f,0,SEEK_END); long long fs=_ftelli64(f); fseek(f,0,SEEK_SET);
  unsigned char*d=malloc(fs); fread(d,1,fs,f); fclose(f);
  unsigned toc=be32(d+8), cnt=be32(d+12); size_t o=toc; int ok=0,bad=0;
  for(unsigned i=0;i<cnt;i++){
    unsigned n=be32(d+o); char name[512]; memcpy(name,d+o+4,n); name[n]=0; o+=4+n;
    unsigned off=be32(d+o), us=be32(d+o+4), cs=be32(d+o+8); o+=24;
    if(argc>3 && !strstr(name,argv[3])) continue;
    unsigned char*u=malloc(us+1); int rc=-1;
    int wb[]={17,15,16,18,19,20,21}; for(int k=0;k<7&&rc!=0;k++) rc=unpack(d+off,cs,u,us,wb[k]);
    if(rc){ bad++; fprintf(stderr,"FAIL %s rc=%d\n",name,rc); free(u); continue; }
    char path[1024]; snprintf(path,sizeof path,"%s/%s.bin",argv[2],name); mkdirs(path);
    FILE*w=fopen(path,"wb"); fwrite(u,1,us,w); fclose(w); free(u); ok++;
  }
  printf("ok %d fail %d\n",ok,bad); return bad?1:0;
}
