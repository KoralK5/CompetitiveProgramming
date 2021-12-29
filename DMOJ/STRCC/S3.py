def primes(n):
    p = [True]*n
    ans = [2]
    for i in range(3,n,2):
        if p[i]:
            ans.append(i)
            for j in range(2*i,n,i):
                p[j] = False
    return ans

A,B=[],[]
for t in range(int(input())):
    i,j = map(int, input().split())
    A.append(i)
    B.append(j)

p=primes(max(B))
for a,b in zip(A,B):
    ans=0
    for i in range(1, len(p)-1):
        if p[i+1] > b: break
        ans += p[i] if p[i-1] >= a and p[i-1]+6 == p[i+1] else 0

    if a<=3 and b>=7:
        ans+=5
    if a<=2 and b>=5:
        ans+=3

    print(ans)
