k = input()
x, y = ord(k[0])-96, int(k[1])

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
dxb = [2, -2, -2, 2]
dyb = [2, -2, 2, -2]

bk = False
for i in range(4):
    rx = x+dx[i]
    ry = y+dy[i]
    for j in range(4):
        bx = x+dxb[j]
        by = y+dyb[j]
        if 0<rx<9 and 0<ry<9 and 0<bx<9 and 0<by<9:
            print(chr(rx+96), end='')
            print(ry, end=' ')
            print(chr(bx+96), end='')
            print(by)
            bk = True
            break
    if bk:
        break
