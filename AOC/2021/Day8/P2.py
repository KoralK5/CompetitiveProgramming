f = open('P.txt').read().split('\n')[:-1]
f = [[j.split(' ') for j in i.split(' | ')] for i in f]

ans=0
for i in f:
    nums = ['' for _ in range(10)]
    for j in i[0]:
        j = ''.join(sorted(j))
        if len(j) == 2:
            nums[1] = j 
        elif len(j) == 3:
            nums[7] = j
        elif len(j) == 4:
            nums[4] = j
        elif len(j) == 7:
            nums[8] = j

    for j in i[0]:
        j = ''.join(sorted(j))
        if len(j)==6:
            if len(set(nums[7]).intersection(set(j))) == 2:
                nums[6] = j
            elif len(set(nums[4]).intersection(set(j))) == 4:
                nums[9] = j
            else:
                nums[0] = j

    for j in i[0]:
        j = ''.join(sorted(j))
        if len(j)==5:
            if len(set(nums[6]).intersection(set(j))) == 5:
                nums[5] = j
            elif nums[1][0] in j and nums[1][1] in j:
                nums[3] = j
            else:
                nums[2] = j

    ac=''
    for v in i[1]:
        ac += str(nums.index(''.join(sorted(v))))
    ans+=int(ac)

print(ans)

