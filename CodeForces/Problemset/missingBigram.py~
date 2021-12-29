for t in range(int(input())):
    n = int(input())-2
    line = input().split()
    print(line[0][0], end='')
    for i in range(len(line)-1):
        if line[i][1] == line[i+1][0]:
            print(line[i][1], end='')
            n-=1
        else:
            print(line[i][1] + line[i+1][0], end='')
            n-=2
    print(line[-1][1] + 'a'*n)
