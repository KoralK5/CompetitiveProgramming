for t in range(int(input())):
    print(f'Case #{t+1}:', end=' ')
    n = input()
    sm = 0
    for i in n:
        sm += int(i)
    
    md = sm%9
    if md == 0:
        print(n[0] + '0' + n[1:])
    else:
        val = 9 - md
        pt = False
        for i in range(len(n)):
            if int(n[i]) > val and not pt:
                print(n[:i] + str(val) + n[i:])
                pt = True
        if not pt:
            print(n + str(val))
