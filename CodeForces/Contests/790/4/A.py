for i in range(int(input())):
    a = list(input())
    if int(a[0]) + int(a[1]) + int(a[2]) == int(a[-1]) + int(a[-2]) + int(a[-3]):
        print('YES')
    else:
        print('NO')
