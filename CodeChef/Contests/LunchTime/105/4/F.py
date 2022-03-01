d = int(input())
if d%2 == 0:
    d //= 2
    ox = 0
    oy = 0
    print(ox-d, oy)
    print(ox+d, oy)
    print(ox, oy-d)
    print(ox, oy+d)
else:
    print(-1)
