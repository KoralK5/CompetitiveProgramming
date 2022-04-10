n, m = map(int, input().split())
d = list(map(int, input().split()))
r = list(map(int, input().split()))

pt = False
for i in range(1, 10):
    if i in d and i in r:
        print(i)
        pt = True
        break

if not pt:
    md = min(d)
    mr = min(r)
    print(str(min(md, mr)) + str(max(md, mr)))
