def solve(f):
    d = [i.split('..') for i in open(f'{f}.txt').read().split(' ')[2:]]
    x1, x2, y1, y2 = int(d[0][0][2:]), int(d[0][1][:-1]), int(d[1][0][2:]), int(d[1][1][:-1])
    x1, x2 = min(x1,x2), max(x1,x2)
    y1, y2 = min(y1,y2), max(y1,y2)

    count = 0
    for xd in range(500):
        for yd in range(-200, 1000):
            xv, yv, = xd, yd
            x, y = 0, 0
            for trial in range(1000):
                x += xv
                y += yv
                if xv>0: xv-=1
                elif xv<0: xv+=1
                yv -= 1

                if x > x2 or y < y1:
                    break

                if x1<=x<=x2 and y1<=y<=y2:
                    count += 1
                    break

    print(count)

solve('T')
solve('P')

