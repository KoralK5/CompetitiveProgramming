from collections import defaultdict as dd

attempts = dd(int)

pen = ac = 0
for i in range(int(input())):
    t, p, v = input().split()
    if v == 'OK':
        if attempts[p] != -1:
            ac += 1
            h, m = map(int, t.split(':'))
            pen += (h*60 + m) + 20 * attempts[p]
            attempts[p] = -1
    elif v != 'CE' and attempts[p] != -1:
        attempts[p] += 1

print(ac, pen)

