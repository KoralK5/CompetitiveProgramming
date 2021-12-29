f = open('P.txt').read().split('\n')[:-1]
bits = [0,0,0,0,0,0,0,0,0,0,0,0]
for i in range(len(f)):
    for j in range(len(f[i])):
        bits[j] += int(f[i][j])

g,e='',''
s = len(f)/2
for i in bits:
    if int(i) > s:
        g += str(1)
        e += str(0)
    else:
        g += str(0)
        e += str(1)

print(int(g,2)*int(e,2))

