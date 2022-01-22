n, T = map(int, input().split())
a = [int(i)-1 for i in input().split()]

d = {}
for i in range(n):
    d[i] = []

for i in range(n):
    d[i].append(a[i])

for t in range(T):
    throwing = []
    for k in d.keys():
        if len(d[k]):
            throwing.append((k, d[k].pop(0)))
    for i in throwing:
        d[i[1]].append(i[0])
        a[i[0]] = i[1]

for i in range(n):
    print(a[i]+1, end=' '*(i!=n-1))
print()
