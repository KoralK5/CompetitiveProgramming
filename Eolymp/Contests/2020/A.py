for t in range(int(input())):
    s = input() 
    print(s[0].lower(), end='')
    for i in s[1:]:
        if i.isupper():
            print('_', end=i.lower())
        else:
            print(i, end='')
    print()
