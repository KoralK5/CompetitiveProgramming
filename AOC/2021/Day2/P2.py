f = open('P.txt').read().split('\n')[:-1]

x,y,a=0,0,0
for i in f:
    d, c = i.split()
    c = int(c)
    if d == 'forward':
        x+=c
        y+=c*a
    elif d == 'down':
        a+=c
    elif d == 'up':
        a-=c

print(x*y)

