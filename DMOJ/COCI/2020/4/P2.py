for i in range(int(input())):
    a, b, c, d = map(int, input().split())

    f = 1;
    for i in range(a, b+1):
        f *= i

    s = 1
    for i in range(c, d+1):
        s *= i

    print("DA" if s%f==0 else "NE")
