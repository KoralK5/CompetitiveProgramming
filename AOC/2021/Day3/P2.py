from copy import deepcopy as dp

fo = open('P.txt').read().split('\n')[:-1]
fc = dp(fo)

size = len(fo[0])
idx = 0
while idx < size:
    try:
        ccount = 0
        for i in fc:
            ccount += int(i[idx])

        big = '1' if ccount>=len(fc)/2 else '0'
        i=0
        while i < len(fc):
            if fc[i][idx] != big:
                fc.pop(i)
            else:
                i+=1
    except: pass

    try:
        ocount = 0
        for i in fo:
            ocount += int(i[idx])
 
        small = '0' if ocount>=len(fo)/2 else '1'
        i=0
        while i < len(fo):
            if fo[i][idx] != small:
                fo.pop(i)
            else:
                i+=1
    except: pass

    idx+=1
    if len(fo)==1:a1=fo[0]
    if len(fc)==1:a2=fc[0]

print(int(a1,2)*int(a2,2))

