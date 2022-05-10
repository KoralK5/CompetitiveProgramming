MOD = 998244353

def bit_set(n, k):
    return n & (1 << k);

n = int(input())
a = list(map(int, input().split()))

m = int(input())
for i in range(m):
    p = list(map(int, input().split()))
    c = p[0]
    p = p[1:]

    ans = 0
    for j in range(2**n):
        prod = 1
        for k in range(n):
            if bit_set(j, k):
                prod *= a[k]

        wk = True
        for i in p:
            if prod%i:
                wk = False
                break

        ans = (ans+wk)%MOD

    print(ans)

