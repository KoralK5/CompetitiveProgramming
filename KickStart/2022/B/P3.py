for t in range(int(input())):
    n, d = map(int, input().split())
    a = input().split('0')
    ans = 0
    for i in a:
        if '1' in i:
            ans += 1
    print(f'Case #{t+1}:', ans)
