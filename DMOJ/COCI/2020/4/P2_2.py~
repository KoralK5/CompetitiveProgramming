from math import sqrt

e = 2.7182818284590452353602874713527
pi = 3.141592653589793238462643383279502884197169399375105820

def fact(n):
    if (n <= 10):
        res = 1
        for i in range(1, n+1):
            res *= i
        return res

    return round(sqrt(2*pi*n) * (n/e)**n * (1 + 1/(12*n) + 1/(288*n**2) - 139/(51840*n**3) - 571/(2488320*n**4)))

for i in range(int(input())):
    a, b, c, d = map(int, input().split())
    fa = fact(a)
    fb = fact(b)
    fc = fact(c)
    fd = fact(d)

    if (fb-fa > fd-fc):
        print("NE")
    else:
        print("DA")
