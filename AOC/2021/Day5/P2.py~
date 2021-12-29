f = open('P.txt').read().split('\n')[:-1]
d = [[[int(k) for k in j.split(',')] for j in i.split(' -> ')] for i in f]

maxX, maxY, minX, minY = 0, 0, float('inf'), float('inf')
for i in d:
    for j in i:
        maxX = max(j[0], maxX)
        maxY = max(j[1], maxY)
        minX = min(j[0], minX)
        minY = min(j[1], minY)

dia = [[0 for _ in range(maxY+1)] for _ in range(maxX+1)]

for i in d:
    x1,y1,x2,y2 = i[0][0],i[0][1],i[1][0],i[1][1]
    if y1==y2:
        for x in range(min(x1,x2), max(x1,x2)+1):
            dia[y1][x] += 1
    elif x1==x2:
        for y in range(min(y1,y2), max(y1,y2)+1):
            dia[y][x1] += 1
    else:
        for x in range(x1,x2+(1 if x1<x2 else -1), 1 if x1<x2 else -1):
            dia[y1][x] += 1
            if y1<y2:y1+=1
            else: y1-=1

count=0
for row in dia:
    for col in row:
        count += col>1

print(count)
