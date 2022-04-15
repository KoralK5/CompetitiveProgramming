n = int(input())
sites = []
for i in range(n):
    sites.append(input())

ans = set()
for i in range(len(sites)):
    if 'yubo' in sites[i]:
        ans.add(sites[i])
        if i != 0:
            ans.add(sites[i-1])
        if i != len(sites)-1:
            ans.add(sites[i+1])

ans = sorted(list(ans))
print('\n'.join(ans))
