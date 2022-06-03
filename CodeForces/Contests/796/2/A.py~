res = []
for t in range(int(input())):
    n = int(input())
    s = bin(n)[2:]
    cnt = 0
    idx = len(s)
    for i in range(len(s)):
        if s[i] == '1':
            idx = i
            cnt += 1

    if s == '1':
        res.append(3)
    elif cnt > 1:
        a = list(s)
        for i in range(len(s)):
            a[i] = '0'
        a[idx] = '1'
        a = a[idx:]
        a = ''.join(a)

        res.append(int(a, 2))
    else:
        a = list(s)
        a[len(a)-1] = '1'
        a = a[idx:]
        a = ''.join(a)

        res.append(int(a, 2))

print('\n'.join(map(str, res)))
