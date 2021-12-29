f = [int(i) for i in open('P.txt').read().split(',')]

for d in range(80):
    new = []
    for i in range(len(f)):
        f[i] -= 1
        if f[i] == -1:
            new.append(8)
            f[i] = 6
    f += new

print(len(f))


