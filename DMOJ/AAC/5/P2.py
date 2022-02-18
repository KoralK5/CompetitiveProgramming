import sys

def ask(i, j):
    print(f'? {i} {j}')
    return int(input())

def pt(a, b, c):
    print('!', a, b, c)

n = int(input())

if (n == 3):
    a = ask(1, 2);
    b = ask(2, 3);
    
    if (a==2 and b==6): pt(1,2,3);
    if (a==3 and b==6): pt(1,3,2);
    if (a==6 and b==3): pt(2,3,1);
    if (a==2 and b==3): pt(2,1,3);
    if (a==6 and b==2): pt(3,2,1);
    if (a==3 and b==2): pt(3,1,2);

else:
    ab = ask(1, 2)
    ac = ask(1, 3)
    bc = ask(2, 3)

    bDc = ab/ac
    b = round((bDc*bc)**(0.5));
    a = int(ab/b);
    c = int(bc/b);

    arr = [a, b, c]
    sa = [0 for i in range(n)]
    sa[a-1] = 1
    sa[b-1] = 1
    sa[c-1] = 1

    for i in range(3, n-1):
        arr.append(int(ask(i, i+1)/arr[-1]))
        sa[arr[i]-1] = 1

    print('!', end=' ')
    for i in arr:
        print(i, end=' ')

    prt = False
    for i in range(n):
        if sa[i] == 0:
            print(i+1)
            prt = True
            break
    if not prt: print(n)
