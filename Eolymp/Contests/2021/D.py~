que = list()
while True:
    s = input()
    if s[0] == '1':
        k, p = map(int, s.split()[1:])
        que.append((p, k))

    elif s[0] == '2':
        if len(que) == 0:
            print(0)
            continue
        que.sort()
        print(que[-1][1])
        que = que[:-1]

    elif s[0] == '3':
        if len(que) == 0:
            print(0)
            continue
        que.sort()
        print(que[0][1])
        que = que[1:]
    else:
        break
