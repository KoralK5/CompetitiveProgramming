from fractions import Fraction as fr

res = []
for i in range(int(input())):
    a, b, c, d = map(, input().split())
    f1 = fr(a, b);
    f2 = fr(c, d);
    if f1 == f2:
        res.append(0)
    elif f1==0 or f2==0 or f1/f2 == f1//f2 or f2/f1 == f2//f1:
        res.append(1)
    else:
        res.append(2)

print('\n'.join(map(str, res)))
