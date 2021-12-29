f = open('P.txt').read().split('\n')[:-1]
f = [[j.split(' ') for j in i.split(' | ')] for i in f]

ans=0
for i in f:
    d1,d7,d4,d8 = '', '', '', ''
    for j in i[0]:
        if len(j) == 2:
            d1 = sorted(j)
        elif len(j) == 3:
            d7 = sorted(j)
        elif len(j) == 4:
            d4 = sorted(j)
        elif len(j) == 7:
            d8 = sorted(j)

    for v in i[1]:
        if sorted(v) in (d1,d4,d7,d8):
            ans += 1

print(ans)
