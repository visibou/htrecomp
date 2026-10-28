# xref.py <hex VA>...  -> functions in generated/*.cpp that build the address
# with a lis/addi (or lis/ori) pair, i.e. that reference that string or global.
import sys, re, glob, os
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
G = os.environ.get('HT_GENERATED', os.path.join(ROOT, 'generated'))
targets = {}
for a in sys.argv[1:]:
    va = int(a, 16)
    hi = (va + 0x8000) >> 16
    targets[a] = (hi - 0x10000 if hi >= 0x8000 else hi, va - (hi << 16), va & 0xFFFF)
lis_re = re.compile(r'\s*// lis (r\d+),(-?\d+)')
add_re = re.compile(r'\s*// (?:addi|ori) (r\d+),(r\d+),(-?\d+)')
for f in sorted(glob.glob(os.path.join(G, '*.cpp'))):
    func, regs = None, {}
    for n, line in enumerate(open(f, encoding='latin-1'), 1):
        if line.startswith('DEFINE_REX_FUNC'):
            func, regs = line.split('(')[1].split(')')[0], {}
            continue
        m = lis_re.match(line)
        if m:
            regs[m.group(1)] = int(m.group(2)); continue
        m = add_re.match(line)
        if m and m.group(2) in regs:
            for a, (hi, lo, lo_ori) in targets.items():
                if regs[m.group(2)] == hi and int(m.group(3)) in (lo, lo_ori):
                    print(a, func, '%s:%d' % (os.path.basename(f), n))
