x = int(input())
same = []
for i in range(x):
    same.append(input().split())

y = int(input())
diff = []
for i in range(y):
    diff.append(input().split())

groups = {}
g = int(input())
for i in range(g):
    a, b, c = input().split()
    groups[a] = [b, c]
    groups[b] = [a, c]
    groups[c] = [b, a]

ans = 0
for i in same:
    if (groups[i[0]][0]!=i[1] and groups[i[0]][1]!=i[1]):
        ans += 1

for i in diff:
    if (groups[i[0]][0]!=i[1] and groups[i[0]][1]!=i[1]):
        ans += 1

print(ans)
