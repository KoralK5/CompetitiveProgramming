from collections import defaultdict 

n=int(input())
m=int(input())
k=int(input())

c=defaultdict(bool)
for i in range(k):
    a,l = input().split()
    l=int(l)-1
    if a=='R':
        for i in range(m):
            if c[(l,i)]:
                c.pop((l,i))
            else:
                c[(l,i)]=True
    else:
        for i in range(n):
            if c[(i,l)]:
                c.pop((i,l))
            else:
                c[(i,l)]=True

print(len(c))
