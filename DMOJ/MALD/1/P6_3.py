import math

def intersection(distance, radius1, radius2):
    r = radius1;
    R = radius2;
    d = distance;
    if R < r:
        r = radius2;
        R = radius1;

    part1 = r*r*math.acos((d*d + r*r - R*R)/(2*d*r));
    part2 = R*R*math.acos((d*d + R*R - r*r)/(2*d*R));
    part3 = 0.5*math.sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));

    return part1 + part2 - part3;

ans = 0
n = int(input())
circles = []
for i in range(n):
    x, y, h, r = map(float, input().split())
    circles.append([x, y, h, r])
    ans += math.pi*r**2

for i in range(n):
    for j in range(n):
        if i == j: continue

        x0, y0, h0, r0 = circles[i]
        x1, y1, h1, r1 = circles[j]

        distance = math.sqrt((x0-x1)**2 + (y0-y1)**2)
        ans -= intersection(distance, r0, r1)

print(ans/10)
