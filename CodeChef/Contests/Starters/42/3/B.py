res = []
for t in range(int(input())):
    n = int(input())
    s = input()
    ans = (s[-1] == '0')
    s = s.split('0')
    ans += sum([len(i)>0 for i in s])
    res.append(str(ans))
print('\n'.join(res))
