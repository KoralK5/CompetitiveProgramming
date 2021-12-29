for _ in range(int(input())):
    num = list(input())
    k = int(input())
    rem = {str(i):0 for i in range(1,10)} 

    s,l = 0,0
    f = False
    for _ in range(k):
        for i in range(s, len(num)-1):
            if int(num[i]) > int(num[i+1]):
                rem[num.pop(i)] += 1
                s = i-1
                break
        if s == len(num) - 2 and l < k:
            f = True
        if s == len(num) - 1:
            break
        l += 1

    if f:
        for v in range(1, int(num[-1])):
            if rem[str(v)]:
                rem[num.pop(-1)] += 1
                break

    print(''.join(num), end='') 
    for v in range(1,10): 
        print(rem[str(v)]*str(v), end='')
    print()
