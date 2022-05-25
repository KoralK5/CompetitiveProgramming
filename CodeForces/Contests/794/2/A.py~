def solve():
    n = int(input())
    a = list(map(int, input().split()))
    sm = sum(a)
    for i in a:
        if i == (sm-i)/(n-1):
            print('YES')
            return
    print('NO')

T = int(input())
for t in range(T):
    solve()
