def count(line):
    ops = {'(':[], '[':[], '{':[], '<':[]}
    idx = 0
    while idx < len(line):
        try:
            if line[idx] in '([{<':
                ops[line[idx]].append(idx)
            else:
                if line[idx] == ')' and len(ops['(']):
                    line.pop(idx)
                    line.pop(ops['('].pop())

                elif line[idx] == ']' and len(ops['[']):
                    line.pop(idx)
                    line.pop(ops['['].pop())

                elif line[idx] == '}' and len(ops['{']):
                    line.pop(idx)
                    line.pop(ops['{'].pop())

                elif line[idx] == '>' and len(ops['<']):
                    line.pop(idx)
                    line.pop(ops['<'].pop())

                idx -= 2
            idx += 1
        except:
            break

    count = 0
    for i in line[::-1]:
        if i=='(': count = 5*count+1
        if i=='[': count = 5*count+2
        if i=='{': count = 5*count+3
        if i=='<': count = 5*count+4
    return count

def solve(f):
    d = map(list, open(f'{f}.txt').read().splitlines())
    ans = []
    for row in d:
        ans.append(count(row))
    ans.sort()
    print(ans)
    print(ans[len(ans)//2])
    
solve('T')
solve('P')

