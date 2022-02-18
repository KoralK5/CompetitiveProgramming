from collections import defaultdict as dd

n = int(input())
t = int(input())
trees = dd(bool)

def expand(i, j, res):
    for x in range(res):
        if trees[(i+res, j+x)]:
            return False
    for y in range(res):
        if trees[(i+y, j+res)]:
            return False
    return True

def best(i, j):
    if trees[(i, j)]: return 0
    for res in range(n):
        if max(i, j) + res > n:
            return res
        if not expand(i, j, res):
            return res
    return n

for i in range(t):
    r, c = map(int, input().split())
    trees[(r, c)] = True

ans = 0
for i in range(1, n+1):
    for j in range(1, n+1):
        ans = max(ans, best(i, j))

print(ans)
