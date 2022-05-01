for t in range(int(input())):
    print(f'Case #{t+1}:', end=' ')
    a = input()
    b = input()
    cur = 0
    ans = 0
    for i in range(len(b)):
        if cur < len(a) and b[i] == a[cur]:
            cur += 1
        else:
            ans += 1
    if cur >= len(a):
        print(ans)
    else:
        print('IMPOSSIBLE')
