res = []
for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = a.count(0)
    res.append(str(n - ans))

print('\n'.join(res))
