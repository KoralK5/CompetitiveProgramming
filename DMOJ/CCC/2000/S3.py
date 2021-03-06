n = int(input())
m = dict()
for i in range(n):
    key = input()
    while True:
        line = input()
        if line == '</HTML>':
            break
        for i in range(line.count('HREF')):
            val = line[line.index('HREF="')+6:line.index('">')]
            print(f'Link from {key} to {val}')
            if key in m.keys():
                m[key].append(val)
            else:
                m[key] = [val]
            line = line[line.index('">')+2:]

def dfs(seen, val, dest):
    global found
    if val == dest:
        found = True
        return
    if val in m.keys() and val not in seen:
        seen.add(val)
        for node in m[val]:
            dfs(seen, node, dest)

while True:
    found = False
    s = input()
    if s == 'The End':
        break
    f = input()
    dfs(set(), s, f)
    ans = "" if found else "'t"
    print(f'Can{ans} surf from {s} to {f}.')

