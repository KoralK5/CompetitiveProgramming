while True:
    n = input()
    if n == '99999': break
    s = int(n[0]) + int(n[1])
    if s==0:
        print(prev, end=' ')
    elif s%2:
        print('left', end=' ')
        prev = 'left'
    else:
        print('right', end=' ')
        prev = 'right'

    print(n[2:])
