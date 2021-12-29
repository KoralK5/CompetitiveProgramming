from collections import defaultdict as dd

f = [int(i) for i in open('P.txt').read().split(',')]
v = dd(int)

for i in f:
    v[i] += 1

for d in range(256):
    p1 = v[1]
    for i in range(1, 8):
        v[i] = v[i+1]
    v[8] = v[0]
    v[6] += v[0]
    v[0] = p1 

print(sum(v.values()))

