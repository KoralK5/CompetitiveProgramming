from collections import defaultdict as dd

res = ''

n = int(input())
mp = dd(str)
for i in range(n):
    cur = input().split()
    if cur[0] == '#define':
        mp[cur[1]] = cur[2]
        res += '\n'
    elif cur[0] == '#undef':
        mp[cur[1]] = ''
        res += '\n'
    else:
        cur = ' '.join(cur)
        for i in mp:
            if not mp[i]:
                continue
            cur = cur.replace(i, mp[i])
            
        res += cur + '\n'

print(res)
