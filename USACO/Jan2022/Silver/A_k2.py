def stepCount(n):
    count = 0
    while n > 1:
        if n % 2 == 0:             # bitmask: *0
            n = n // 2
        elif n == 3 or n % 4 == 1: # bitmask: 01
            n = n - 1
        else:                      # bitmask: 11
            n = n + 1
        count += 1
    return count

for i in range(int(input())):
    a, b = map(int, input().split())
    print(stepCount(a-b)+1)
