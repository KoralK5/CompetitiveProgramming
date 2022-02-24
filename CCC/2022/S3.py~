n, m, k = map(int, input().split())

res = []
same = False
ans, cur = 0, 0
for i in range(n):
    if same:
        res.append(res[-1])
    # this is probably >=
    elif ans == k - cur:
        res.append(1)
        same = True
        ans = k
    elif ans == k - n:
        cur = cur%m + 1
        res.append(cur)
        same = True
        ans = k
    else:
        cur = cur%m + 1
        res.append(cur)
        ans += cur
    # print(ans, res)

print(-1 if ans!=k else ' '.join(map(str, res)))
