def solve(d):
    f = ['9' + i + '9' for i in open(f'{d}.txt').read().split('\n')[:-1]]
    f = ['9'*len(f[0])] + f + ['9'*len(f[0])]
    ans=0
    for i in range(1,len(f)-1):
        for j in range(1,len(f[i])-1):
            if int(f[i][j]) < int(f[i+1][j]) and int(f[i][j]) < int(f[i-1][j]) and int(f[i][j]) < int(f[i][j+1]) and int(f[i][j]) < int(f[i][j-1]):
                ans += int(f[i][j])+1
    print(ans)

solve('T')
solve('P')
