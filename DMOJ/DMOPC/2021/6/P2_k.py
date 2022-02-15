n, k = map(int, input().split())
s = sorted([len(i) for i in input().split('1')], reverse=True)
ans = 0
for i in range(len(s)):
    if i == k: break
    ans += s[i]
print(ans)
