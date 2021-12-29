def score(line):
    for c in line:
        if c==')': return 3
        if c==']': return 57
        if c=='}': return 1197
        if c=='>': return 25137
    return 0

def solve(f):
    d = open(f'{f}.txt').read().splitlines()
    count = 0
    for line in d:
        for _ in range(len(line)):
            line = line.replace('()', '')
            line = line.replace('[]', '')
            line = line.replace('{}', '')
            line = line.replace('<>', '')
        count += score(line)
    print(count)

solve('T')
solve('P')
