from random import randrange
from collections import defaultdict as dd

n = int(1e5)
m = n*2
print(n, m)

used = dd(bool)

for i in range(m):
    while True:
        u, v, w = randrange(1, n+1), randrange(1, n+1), randrange(1, n+1)
        if not used[(u, v)] and not used[(v, u)]:
            break

    print(u, v, w)
    used[(u, v)] = True;
    used[(v, u)] = True;
