# findfn.py [--self] [--max N] PATTERN... : functions whose PPC listing matches
# every regex PATTERN (searched in the "// asm" comments). --self requires the
# function to call itself. Prints name, size in instructions, location.
import sys, re, glob, os
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
G = os.environ.get('HT_GENERATED', os.path.join(ROOT, 'generated'))
args = sys.argv[1:]
need_self = '--self' in args
maxn = 10 ** 9
if '--max' in args:
    i = args.index('--max'); maxn = int(args[i + 1]); del args[i:i + 2]
pats = [re.compile(p) for p in args if p != '--self']
for f in sorted(glob.glob(os.path.join(G, '*.cpp'))):
    name, body, start = None, [], 0
    def flush():
        if not name or len(body) > maxn: return
        text = '\n'.join(body)
        if need_self and ('bl 0x' + name[4:].lower()) not in text.lower(): return
        if all(p.search(text) for p in pats):
            print(name, len(body), '%s:%d' % (os.path.basename(f), start))
    for n, line in enumerate(open(f, encoding='latin-1'), 1):
        if line.startswith('DEFINE_REX_FUNC'):
            flush(); name, body, start = line.split('(')[1].split(')')[0], [], n
        elif line.startswith('\t// ') or line.startswith('    // '):
            body.append(line.strip()[3:])
    flush()
