f = [int(i) for i in open('P.txt').read().split(',')]

m = float('inf')
for i in range(10000):
    s = 0
    for j in range(len(f)):
        s += abs(f[j] - i)
    if s<m:
        m = max(m, s)

print(m)
