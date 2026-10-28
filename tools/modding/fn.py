# fn.py <sub_XXXXXXXX | file.cpp:line>  -> PPC asm of the enclosing function, strings resolved
#   Run from a source tree: reads <tree>/generated and <tree>/game_data/default.xex
#   (override with HT_GENERATED / HT_XEX).
import sys, re, glob, os
ROOT=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
G=os.environ.get('HT_GENERATED', os.path.join(ROOT,'generated'))
X=open(os.environ.get('HT_XEX', os.path.join(ROOT,'game_data','default.xex')),'rb').read()
def cstr(va):
    o=va-0x82000000+0x3000
    if not (0<=o<len(X)): return None
    s=X[o:o+80].split(b'\0')[0]
    return s.decode('latin-1') if len(s)>=3 and all(32<=c<127 for c in s) else None
arg=sys.argv[1]
if arg.startswith('sub_'):
    name=arg.upper().replace('SUB_','sub_')
    for f in glob.glob(os.path.join(G,'*.cpp')):
        L=open(f,encoding='latin-1').read().split('\n')
        for i,l in enumerate(L):
            if l.startswith('DEFINE_REX_FUNC(%s)'%name): start=i; break
        else: continue
        break
else:
    f,ln=arg.rsplit(':',1); f=os.path.join(G,f); L=open(f,encoding='latin-1').read().split('\n'); ln=int(ln)-1
    start=max(i for i in range(ln+1) if L[i].startswith('DEFINE_REX_FUNC'))
print(L[start])
hi={}
for l in L[start+1:]:
    if l.startswith('DEFINE_REX_FUNC'): break
    m=re.match(r'\s*// (.*)',l)
    if l.startswith('loc_'): print(l); continue
    if not m: continue
    a=m.group(1); note=''
    mm=re.match(r'lis (r\d+),(-?\d+)',a)
    if mm: hi[mm.group(1)]=(int(mm.group(2))<<16)&0xFFFFFFFF
    mm=re.match(r'addi (r\d+),(r\d+),(-?\d+)',a)
    if mm and mm.group(2) in hi:
        va=(hi[mm.group(2)]+int(mm.group(3)))&0xFFFFFFFF; s=cstr(va); note='  ; %08X'%va+(' "%s"'%s if s else '')
    mm=re.match(r'(lwz|stw|lfs|lbz) (r\d+|f\d+),(-?\d+)\((r\d+)\)',a)
    if mm and mm.group(4) in hi: note='  ; [%08X]'%((hi[mm.group(4)]+int(mm.group(3)))&0xFFFFFFFF)
    print('  '+a+note)
