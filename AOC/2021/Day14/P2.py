from collections import defaultdict as dd
from math import ceil

def solve(f):
    d, r = open(f'{f}.txt').read().split('\n\n')
    d = list(d)
    r = [i.split(' -> ') for i in r.splitlines()]

    dc = dd(int)
    for i in range(len(d)-1):
        dc[d[i]+d[i+1]] += 1

    for step in range(40):
        new = dd(int)
        for rule in r:
            new[rule[0][0]+rule[1]] += dc[rule[0]]
            new[rule[1]+rule[0][1]] += dc[rule[0]]
            new[rule[0]] -= dc[rule[0]]

        for i in new.keys():
            dc[i] += new[i]

    dCount = dd(int)
    for i in dc.keys():
        dCount[i[0]] += dc[i]
        dCount[i[1]] += dc[i]

    ma, mi = 0, float('inf')
    for i in dCount.values():
        ma = max(ma, i)
        mi = min(mi, i)

    print(ceil((ma-mi)/2))

solve('T')
solve('P')
