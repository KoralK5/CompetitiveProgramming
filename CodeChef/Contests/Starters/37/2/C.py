res = []
for t in range(int(input())):
    n = int(input())
    s = ''.join(input().split())

    for i in range(n):
        if i%2 == 0:
            if '01' in s:
                s = s.replace('01', '1')
            elif '10' in s:
                s = s.replace('10', '1')
            elif '11' in s:
                s = s.replace('11', '1')
            elif '00' in s:
                s = s.replace('00', '0')
        else:
            if '01' in s:
                s = s.replace('01', '0')
            elif '10' in s:
                s = s.replace('10', '0')
            elif '00' in s:
                s = s.replace('00', '0')
            elif '11' in s:
                s = s.replace('11', '1')
    
    res.append(s)

print('\n'.join(res))
