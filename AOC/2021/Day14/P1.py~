def solve(f):
    d, r = open(f'{f}.txt').read().split('\n\n')
    d = list(d)
    r = [i.split(' -> ') for i in r.splitlines()]
    for step in range(10):
        new = []
        for rule in r:
            for i in range(len(d)-1):
                if d[i] + d[i+1] == rule[0]:
                    new.append((i+1, rule[1]))
        new.sort(key=lambda x:x[0])
        idx = 0
        for i in new:
            d.insert(i[0]+idx, i[1])
            idx += 1
    ma, mi = 0, float('inf')
    for i in set(d):
        c = d.count(i)
        ma = max(ma, c)
        mi = min(mi, c)
    print(ma-mi)

solve('T')
solve('P')
