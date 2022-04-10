n = int(input())
a = list(map(int, input().split()))

if n==1:
    print(a[0])
elif n==2:
    print(max(a[0], a[1]))
elif n==3:
    print(max(a[0]+a[2], a[1]))
else:
    dp = [0 for i in range(n)]
    dp[0] = a[0]
    dp[1] = a[1]
    dp[2] = a[2]+a[0]

    for i in range(3, n):
        dp[i] = a[i] + max(dp[i - 2], dp[i - 3])

    print(max(dp[n - 1], dp[n - 2]))
