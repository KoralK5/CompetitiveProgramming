from collections import defaultdict as dd

def toMap(arr):
    mp = dd(list)
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    for i in range(1, len(arr)-1):
        for j in range(1, len(arr[0])-1):
            for k in range(4):
                x, y = dx[k], dy[k]
                if arr[i+x][j+y]:
                    mp[(i,j)].append((i+x,j+y))
    return mp

def dij(m, arr, node):
    d = dd(float)
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            d[(i,j)] = float('inf')
    d[node] = 0


def solve(f):
    d = [[0] + list(map(int, i)) + [0] for i in open(f'{f}.txt').read().splitlines()]
    d = [[0]*len(d)] + d + [[0]*len(d)]
    m = toMap(d)
    dij(m, d, (0,0))

solve('T')
#solve('P')

