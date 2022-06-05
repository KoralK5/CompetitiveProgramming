for t in range(int(input())):
    l, r = map(int, input().split())
    
    n = '00' + bin(l)[2:]
    a = list(n)
    b = list(n)
    c = list(n)
    d = list(n)

    ones = []
    idxs = []
    for i in range(len(n)-1, -1, -1):
        if n[i] == '0':
            idxs.append(i)
        
        if len(idxs) == 2:
            break

        if n[i] == '1':
            ones.append(i)

    if len(ones) == 0:
        b[idxs[1]] = '1'
        b[ones[0]] = '0'

        c[idxs[0]] = '1'
        c[idxs[1]] = '1'
        c[ones[0]] = '0'

        d[idxs[0]] = '1'

    elif len(ones) == 1:
        b[idxs[0]] = '1'

        c[idxs[0]] = '1'
        c[idxs[1]] = '1'
        c[ones[0]] = '0'

        d[idxs[1]] = '1'
        d[ones[0]] = '0'

    elif len(ones) >= 2:
        a[idxs[0]] = '1'

        b[idxs[0]] = '1'
        b[ones[0]] = '0'

        c[idxs[0]] = '1'
        c[ones[1]] = '0'

        d[idxs[0]] = '1'
        d[ones[0]] = '0'
        d[ones[1]] = '0'

    a = int(''.join(a), 2)
    b = int(''.join(b), 2)
    c = int(''.join(c), 2)
    d = int(''.join(d), 2)

    if a>r or b>r or c>r or d>r:
        print(-1)
    elif a in [b,c,d] or b in [a,c,d] or c in [a,b,d] or d in [a,b,c]:
        print(-1)
    else:
        print(a, b, c, d)
