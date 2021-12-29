num = int(input())
friends = [int(row) for row in input().split()]

if sorted(friends) == list(range(1, num+1)):
	print('YES')
else:
	print('NO')
