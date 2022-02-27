n, T = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for t in range(T):
    arr = [[0 for j in range(n+2)] for i in range(n+2)]
    if n == 2:
        print(2)
    else:
        print(1)
        print(1, 1)
        arr[1][1] = 1

    while True:
        x, y = map(int, input().split())
        if x==0 and y==0:
            break
        else:
            arr[x][y] = -1
        for i in range(1, n+1):
            bk = False
            for j in range(1, n+1):
                if arr[i][j] != 0:
                    continue
                works = True;
                for d in range(4):
                    if arr[i+dx[d]][j+dy[d]] != 0:
                        works = False
                        break
                if works:
                    print(i, j)
                    arr[i][j] = 1
                    bk = True
                    break;
            if bk:
                break
