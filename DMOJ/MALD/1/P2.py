def ceil(a, b):
    return -(a*100 // -b)

n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    k = ceil(a, b)/100
    if k > 1:
        print('sus')
    elif k == 1:
        print('average')
    elif 0.98 <= k <= 99:
        print('below average')
    elif 0.95 <= k <= 0.97:
        print("can't eat dinner")
    elif 0.9 <= k <= 0.94:
        print("don't come home")
    else:
        print('find a new home')
