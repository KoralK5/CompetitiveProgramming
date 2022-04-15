import math

def aoi(x0, y0, r0, x1, y1, r1):
    rr0 = r0 * r0;
    rr1 = r1 * r1;
    d = math.sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));

    if (d > r1 + r0):
        return 0;

    elif (d <= abs(r0 - r1) and r0 >= r1):
        return math.pi * rr1;

    elif (d <= abs(r0 - r1) and r0 < r1):
        return math.pi * rr0;

    else:
        phi = (math.acos((rr0 + (d * d) - rr1) / (2 * r0 * d))) * 2;
        theta = (math.acos((rr1 + (d * d) - rr0) / (2 * r1 * d))) * 2;
        area1 = 0.5 * theta * rr1 - 0.5 * rr1 * math.sin(theta);
        area2 = 0.5 * phi * rr0 - 0.5 * rr0 * math.sin(phi);
        return area1 + area2;

ans = 0
n = int(input())
circles = []
for i in range(n):
    x, y, h, r = map(float, input().split())
    circles.append([x, y, h, r])
    ans += math.pi*r**2

for i in range(n):
    for j in range(n):
        if i == j:
            continue

        x0, y0, h0, r0 = circles[i]
        x1, y1, h1, r1 = circles[j]
        ans -= aoi(x0, y0, r0, x1, y1, r1)

print(ans/10)
