f = [int(i) for i in open('P.txt').read().split(',')]

m = float('inf')
for i in range(10000):
    s = 0
    for j in range(len(f)):
        n = abs(f[j] - i)
        s += n*(n+1)/2
    m = min(m, s)

print(m)

