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

p=primes(max(B)+1)
for a,b in zip(A,B):
    ans=0
    for i in p:
        if i > b: break
        ans += i if i>=a else 0
    print(ans)
