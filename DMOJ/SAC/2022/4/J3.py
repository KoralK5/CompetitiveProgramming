import math

n, a = map(int, input().split())

idx = 0
d = 1e18
for i in range(n):
    x, y = map(float, input().split())
    if x == y == 0:
        continue
    elif x == 0:
        if y > 0:
            ang = 90
        if y < 0:
            ang = 270
    elif y == 0:
        if x > 0:
            ang = 0
        if x < 0:
            ang = 180
    else:
        ang = math.degrees(math.atan(y/x))
    
    # print(ang, 360-ang)
    if ang >= 0:
        curD = min(abs(a-ang), abs((360-ang)-a))
        if curD < d:
            idx = i
            d = curD
    else:
        curD = min(abs(a-ang), abs((360+ang)-a))
        if curD < d:
            idx = i
            d = curD



print(idx+1)
