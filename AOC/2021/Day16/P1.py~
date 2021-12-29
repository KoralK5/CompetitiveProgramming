def toBin(x):
    return bin(int(x, 16))[2:].zfill(4)

count = 0

def rec(bits):
    global count
    ver = int(bits[:3], 2)
    ids = int(bits[3:6], 2)
    con = ''
    if ids == 4:
        for i in range(6, len(bits), 5):
            con += bits[i+1:i+5]
            if bits[i] == '0':
                break
    elif ids == 0:
        subs = int(bits[:15])
    elif ids == 1:
        subs = int(bits[:11])

    if len(con) != 0:
        count += int(con, 2)
        rec(con)

def solve(f):
    d = open(f'{f}.txt').read()[:-1]
    bits = ''.join([toBin(i) for i in d])
    rec(bits)
    print(count)

solve('T')
#solve('P')
