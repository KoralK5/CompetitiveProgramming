n = int(input())
v = []
for i in range(n):
    v.append(int(input()))

v.sort()
ans = 2000000000
for i in range(1, n-1):
    ans = min(ans, v[i]-(v[i]+v[i-1])/2 + v[i+1]-(v[i]+v[i+1])/2);

print(ans)
