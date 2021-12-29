def solve1(f):
	d = open(f'{f}.txt').read().splitlines()
	for row in range(len(d)):
		d[row] = d[row].replace('x=', '').replace(',y=', ' ').replace(',z=', ' ').split(' ')
	
	mi, ma = -100000, 100000
	enc = range(mi, ma+1)
	area = [[[False for z in enc] for y in enc] for x in enc]
	for cube in d:
		on = cube[0] == 'on'
		x1, x2 = map(int, cube[1].split('..'))
		y1, y2 = map(int, cube[2].split('..'))
		z1, z2 = map(int, cube[3].split('..'))
		x1, x2 = max(mi, x1), min(ma, x2)
		y1, y2 = max(mi, y1), min(ma, y2)
		z1, z2 = max(mi, z1), min(ma, z2)
		for x in range(x1, x2+1):
			for y in range(y1, y2+1):
				for z in range(z1, z2+1):
					area[x][y][z] = on
	
	ans = 0
	for x in area:
		for y in x:
			for z in y:
				ans += z
	print(ans)

def solve2(f):
	return 0

solve1('T')
solve1('P')
