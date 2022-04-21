for i in range(int(input())):
    a = int(input())
    print('Division', end=' ')
    if 1900 <= a:
        print(1)
    elif 1600 <= a <= 1899:
        print(2)
    elif 1400 <= a <= 1599:
        print(3)
    else:
        print(4)

