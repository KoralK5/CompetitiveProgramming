def count(num):
    sm, pd = 0, 1
    for i in str(num):
        sm += int(i)
        pd *= int(i)
    return pd%sm == 0

for t in range(int(input())):
    print(f'Case #{t+1}:', end=' ')
    a, b = map(int, input().split())
    
    ans = 0
    for i in range(a, b+1):
        ans += count(i)
    
    print(ans)
