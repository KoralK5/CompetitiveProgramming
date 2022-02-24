n, m, k = map(int, input().split())
# k -= n

res = []
same = False
ans, cur = 0, 1
for i in range(n):
    if same:
        res.append(res[-1])
    elif ans == k:
        res.append(1)
        same = True
        ans = k
    elif ans == k - 1:
        res.append(cur)
        same = True
        ans = k
    else:
        res.append(cur)
        cur = cur%m + 1
        ans += cur
    # print(ans)

print(-1 if ans!=k else ' '.join(map(str, res)))
