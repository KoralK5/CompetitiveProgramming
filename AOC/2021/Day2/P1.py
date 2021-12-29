f = open('P.txt').read().split('\n')[:-1]

x,y=0,0
for i in f:
    d, c = i.split()
    c = int(c)
    if d == 'forward':
        x+=c
    elif d == 'down':
        y+=c
    elif d == 'up':
        y-=c

print(x*y)

