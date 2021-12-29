def solve(x):
    x = x.split(' ')
    ans = 0
    for row in x:
        if row[-1] == 'A':
            ans += int(row[:-1])*1
        if row[-1] == 'B':
            ans += int(row[:-1])*10
        if row[-1] == 'C':
            ans += int(row[:-1])*100
        if row[-1] == 'D':
            ans += int(row[:-1])*1000
    print(ans)

order = '2C 7A 5C 2C 6B 3A 8D 3B 4B 9D 3A 8A'
solve(order)
