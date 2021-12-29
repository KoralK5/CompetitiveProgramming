import random

def primes(n):
    p = [True]*n
    ans = [2]
    for i in range(3,n,2):
        if p[i]:
            ans.append(i)
            for j in range(2*i,n,i):
                p[j] = False
    return ans

inputFile = open('S3_input.txt', 'a')
outputFile = open('S3_output.txt', 'a')

for case in range(1,7):
    print(f'case #{case}')
    T = random.randrange(1, 10**case)
    inputFile.write(f'{T}\n')

    A,B=[],[]
    for t in range(T):
        i = random.randrange(1, 10**case-1)
        j = random.randrange(i, 10**case)
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

        inputFile.write(f'{a} {b}\n')
        outputFile.write(f'{ans}\n')
    inputFile.write(f'\n')
    outputFile.write(f'\n')
