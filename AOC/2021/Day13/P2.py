def solve(f):
    d, ins = open(f'{f}.txt').read().split('\n\n')
    pg = []
    maxX, maxY = 0, 0
    for coord in d.split('\n'):
        coord = coord.split(',')
        pg.append([int(coord[0]), int(coord[1])])

    ins = [i[i.index('=')-1:] for i in ins.split('\n')[:-1]]
    for i in ins:
        loc = int(i[2:])
        if i[0] == 'x':
            for coord in pg:
                if coord[0] > loc:
                    coord[0] = 2*loc - coord[0]
        else:
            for coord in pg:
                if coord[1] > loc:
                    coord[1] = 2*loc - coord[1]

    mx, my = 0, 0
    for i in pg:
        mx = max(i[0], mx)
        my = max(i[1], my)
        
    arr = [['.' for j in range(mx+1)] for i in range(my+1)]
    for i in pg:
        arr[i[1]][i[0]] = '#'

    for i in arr:
        print(''.join(i))


solve('T')
solve('P')

