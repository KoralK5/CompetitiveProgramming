for t in range(int(input())):
    a, b, n = map(int, input().split())
    bk = False
    for i in range(100):
        for j in range(100):
            if i*a + j*b == n:
                print('YES')
                bk = True
                break
        if bk:
            break
    if not bk:
        print('NO')
