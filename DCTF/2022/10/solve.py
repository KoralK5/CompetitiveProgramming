import os

path = os.path.expanduser('C:\\Users\\kulac\\Coding\\Competitive\\DCTF\\2022\\10\\cfg')

name = []
for root, d_names, f_names in os.walk(path):
    for f in f_names:
        name.append(os.path.join(root, f))

name = [i.split('\\') for i in name]
ans = []

for i in name:
    ans.append((i[-2], i[-1]))

ans.sort()
res = [i[1][0] for i in ans]
fres = ''.join(res)
print(fres)

