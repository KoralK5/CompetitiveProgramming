def solve1(p1, p2):
	points = [0, 0]
	locs = [p1, p2]
	dice = 1
	turn = 0
	while points[0] < 1000 and points[1] < 1000:
		roll = dice
		dice += 1
		roll += dice
		dice += 1
		roll += dice
		dice += 1

		locs[turn] = (locs[turn]+roll)%10 if (locs[turn]+roll)%10!=0 else 10
		points[turn] += locs[turn]
		turn = not(turn)
	
	print(min(points)*(dice-1))

solve1(4, 8)
solve1(1, 3)
