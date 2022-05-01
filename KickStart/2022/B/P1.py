from math import pi

for t in range(int(input())):
    r, a, b = map(float, input().split())
    area = pi*r**2
    ans = area
    for turn in range(100000000000):
        if turn%2:
            r //= b
        else:
            r *= a
            
        area = pi*r**2
        if area == 0:
            break

        ans += area

    print(f'Case #{t+1}:', end=' ')
    print(ans)
