import sys 
sys.setrecursionlimit(10**6) 

count = 1

def show(f):
	global count
	for i in f:
		for j in i:
			print(j[-1], end='')
		print()
	print(count, '\n')

def neighbors(f, i, j):
	for x in range(-1, 2):
		for y in range(-1, 2):
			if not(y==x==0) and f[i+x][j+y]!='9' and 'x' not in f[i+x][j+y]:
				yield (i+x, j+y)
	
def dfs(f,i,j):
	global count
	if f[i][j] != '9' and 'x' not in f[i][j]:
		count += 1
		f[i][j] += 'x'
		#show(f)
		for neigh in neighbors(f, i, j):
			if f[neigh[0]][neigh[1]] < f[i][j][0]:
				dfs(f,neigh[0],neigh[1])

def solve(d):
	global count
	f = open(f'{d}.txt').read().split('\n')
	f = ['9' + ''.join(i) + '9' for i in open(f'{d}.txt').read().split('\n')][:-1]
	f = [['9' for _ in range(len(f[0]))]] + [list(i) for i in f] + [['9' for _ in range(len(f[0]))]] 

	ans=[1,1,1]
	for i in range(1, len(f)-1):
		for j in range(1, len(f[i])-1):
			if f[i][j] != '9' and 'x' not in f[i][j] and int(f[i][j]) >= max([int(f[x][y]) for (x,y) in neighbors(f, i, j)] + [0]):
				count = 1
				dfs(f,i,j)
				if min(ans) < count:
					ans[ans.index(min(ans))] = count

	print(ans)
	print(ans[0]*ans[1]*ans[2])

solve('T')
solve('P')

