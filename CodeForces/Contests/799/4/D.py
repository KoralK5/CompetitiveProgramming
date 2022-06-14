from collections import defaultdict as dd

def pal(h, m):
    return h[0]==m[1] and h[1]==m[0]

def update(h, m, x):
    m += x
    h += m//60
    m %= 60
    h %= 24
    return h, m

cnt = 0
for T in range(int(input())):
    t, x = input().split()
    x = int(x)
    h, m = map(int, t.split(':'))

    seen = dd(bool)
    seen[(h, m)] = True
    while True:
        h, m = update(h, m, x)
        # print(h, m)
        if (seen[(h, m)]):
            break
        seen[(h, m)] = True

    ans = 0
    for i in seen.keys():
        a = str(i[0])
        while len(a) < 2:
            a = '0' + a
        b = str(i[1])
        while len(b) < 2:
            b = '0' + b
        ans += pal(a, b)
    print(ans)
