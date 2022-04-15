import math
from dataclasses import dataclass
from typing import Tuple

@dataclass
class Circle:
    x: float
    y: float
    r: float

    @property
    def coord(self):
        return self.x, self.y


def find_intersection(c1: Circle, c2: Circle) -> float:
    """Finds intersection area of two circles.

    Returns intersection area of two circles otherwise 0
    """

    d = math.dist(c1.coord, c2.coord)
    rad1sqr = c1.r ** 2
    rad2sqr = c2.r ** 2

    if d == 0:
        # the circle centers are the same
        return math.pi * min(c1.r, c2.r) ** 2

    angle1 = (rad1sqr + d ** 2 - rad2sqr) / (2 * c1.r * d)
    angle2 = (rad2sqr + d ** 2 - rad1sqr) / (2 * c2.r * d)

    # check if the circles are overlapping
    if (-1 <= angle1 < 1) or (-1 <= angle2 < 1):
        theta1 = math.acos(angle1) * 2
        theta2 = math.acos(angle2) * 2

        area1 = (0.5 * theta2 * rad2sqr) - (0.5 * rad2sqr * math.sin(theta2))
        area2 = (0.5 * theta1 * rad1sqr) - (0.5 * rad1sqr * math.sin(theta1))

        return area1 + area2
    elif angle1 < -1 or angle2 < -1:
        # Smaller circle is completely inside the largest circle.
        # Intersection area will be area of smaller circle
        # return area(c1_r), area(c2_r)
        return math.pi * min(c1.r, c2.r) ** 2
    return 0


if __name__ == "__main__":

    @dataclass
    class Test:
        data: Tuple[Circle, Circle]
        expected: float

    ans = 0
    n = int(input())
    circles = []
    for i in range(n):
        x, y, h, r = map(int, input().split())
        circles.append([x, y, h, r])
        ans += math.pi*r**2

    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            x0, y0, h0, r0 = circles[i]
            x1, y1, h1, r1 = circles[j]
            it = find_intersection(*Test((Circle(x0, y0, r0), Circle(x1, y1, r1)), 0).data)
            ans -= it

    print(ans/10)
