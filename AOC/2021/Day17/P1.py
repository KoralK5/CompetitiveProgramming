def solve(f):
    d = [i.split('..') for i in open(f'{f}.txt').read().split(' ')[2:]]
    x1, x2, y1, y2 = int(d[0][0][2:]), int(d[0][1][:-1]), int(d[1][0][2:]), int(d[1][1][:-1])
    x1, x2 = min(x1,x2), max(x1,x2)
    y1, y2 = min(y1,y2), max(y1,y2)

    mv = float('-inf')
    for xd in range(-100, 500):
        for yd in range(-100, 1000):
            x, y = 0, 0
            xv, yv = xd, yd
            my = float('-inf')
            for trial in range(1000):
                x += xv
                y += yv
                if xv>0: xv-=1
                elif xv<0: xv+=1
                yv -= 1

                if x > x2 or y < y1:
                    break

                my = max(my, y)
                if x1<=x<=x2 and y1<=y<=y2:
                    mv = max(mv, my)
                    break

    print(mv)

solve('T')
solve('P')
