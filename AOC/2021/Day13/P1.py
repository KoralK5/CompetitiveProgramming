def solve(f):
    d, ins = open(f'{f}.txt').read().split('\n\n')
    pg = []
    for coord in d.split('\n'):
        coord = coord.split(',')
        pg.append([int(coord[0]), int(coord[1])])

    ins = [i[i.index('=')-1:] for i in ins.split('\n')[:-1]]
    for i in ins:
        loc = int(i[2:])
        if i[0] == 'x':
            for coord in pg:
                if coord[0] > loc:
                    coord[0] = loc - coord[0]%loc
        else:
            for coord in pg:
                if coord[1] > loc:
                    coord[1] = loc - coord[1]%loc
        break

    s = set()
    for i in pg:
        s.add(tuple(i))

    print(len(s))


solve('T')
solve('P')
