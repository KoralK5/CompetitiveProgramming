for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s1 = 0
    s2 = sum(a)
    ans = 10000000000
    for i in a:
        s1 += i
        s2 -= i
        ans = min(ans, max(s1, s2))
    print(ans)

