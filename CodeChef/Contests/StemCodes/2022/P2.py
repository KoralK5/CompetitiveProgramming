a = '3 4 5 6 7 8 9 10 11 12'
a = a.split()
res = 1
for i in a:
    res *= int(i)
print(res)
