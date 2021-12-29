def solve(f):
    d = [[float('-inf')] + list(int(col) for col in row) + [float('-inf')] for row in open(f'{f}.txt').read().splitlines()]
    d = [[float('-inf')]*len(d[0])] + d + [[float('-inf')]*len(d[0])]

    step = 0
    while True:
        count = 0
        flashes = []
        for row in range(1, len(d)-1):
            for col in range(1, len(d[row])-1):
                d[row][col] += 1
                if d[row][col] > 9:
                    flashes.append((row, col))
                    d[row][col] = -1
        
        while flashes:
            row, col = flashes.pop()
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if d[row+i][col+j] != -1:
                        d[row+i][col+j] += 1
                        if not(i==j==0) and d[row+i][col+j] > 9:
                            d[row+i][col+j] = -1
                            flashes.append((row+i, col+j))

        for row in range(1, len(d)-1):
            for col in range(1, len(d[row])-1):
                if d[row][col] == -1:
                    d[row][col] = 0
                    count += 1
        step += 1
        if count == (len(d)-2)*(len(d[0])-2):
            break

    print(step)

solve('T')
solve('P')

