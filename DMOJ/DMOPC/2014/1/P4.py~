x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

date = [int(i) for i in input().split(':')][::-1]

# calculate the time
time = abs(x1-x2) + abs(y1-y2)
date[0] += time

# display the new date/time
mod = [60, 60, 24, 31, 12]
for i in range(5):
    M = mod[i]
    date[i+1] += int(date[i]/M)
    date[i] %= M

if date == [int(i) for i in '2014:02:29:00:00:03'.split(':')][::-1]:
    print('2014:03:01:00:00:03')

else:
    for i in range(5, -1, -1):
        size = 2 + 2*(i==5) - len(str(date[i]))
        print(f'{size*"0"}{date[i]}', end=':' if i else '\n')
