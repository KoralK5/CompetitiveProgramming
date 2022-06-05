for t in range(int(input())):
    l, r = map(int, input().split())
    b = bin(r)[2:]

    idxs = []
    for i in range(len(b)):
        if b[i] == '1':
            idxs.append(i)

    zers = []
    for i in range(len(b)):
        if b[i] == '0':
            zers.append(i)

    n1 = ['0' for i in range(len(b))]
    n2 = ['0' for i in range(len(b))]
    n3 = ['0' for i in range(len(b))]
    n4 = ['0' for i in range(len(b))]

    if len(idxs) >= 4:
        n1[idxs[0]] = '1'
        n2[idxs[1]] = '1'
        n3[idxs[2]] = '1'
        n4[idxs[4]] = '1'
        for i in range(4, len(idxs)):
            n4[i] = '1'

    elif len(idxs) == 3:
        if len(zers) == 0:
            print(-1)
            continue

        n1[idxs[0]] = '1'
        n2[idxs[1]] = '1'
        n3[idxs[2]] = '1'
        n3[zers[0]] = '1'
        n4[zers[0]] = '1'

    elif len(idxs) == 2:
        if len(zers) <= 1:
            print(-1)
            continue

        n1[idxs[0]] = '1'
        n2[idxs[1]] = '1'
        n2[zers[0]] = '1'
        n2[zers[1]] = '1'
        n3[zers[0]] = '1'
        n4[zers[1]] = '1'

    elif len(idxs) == 1:
        if len(zers) <= 2:
            print(-1)
            continue

        n1[idxs[0]] = '1'
        n1[zers[0]] = '1'
        n1[zers[1]] = '1'
        n1[zers[2]] = '1'
        n2[zers[0]] = '1'
        n3[zers[1]] = '1'
        n4[zers[2]] = '1'

    a = int(''.join(n1), 2)
    b = int(''.join(n2), 2)
    c = int(''.join(n3), 2)
    d = int(''.join(n4), 2)

    if a < l or b < l or c < l or d < l:
        print(-1)
        continue

    print(a, b, c, d)

