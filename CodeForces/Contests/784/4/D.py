def solve():
    n = int(input())
    s = input().split('W')
    for i in s:
        bs = 'B' in i
        rs = 'R' in i
        if bs ^ rs:
            print('NO')
            return

    print('YES')

for t in range(int(input())):
    solve()
