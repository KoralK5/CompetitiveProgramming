from collections import defaultdict

team = defaultdict(bool)

t = int(input())
for i in range(t):
    a = list(map(int, input().split()))
    for j in range(1, a[0]+1):
        team[a[j]] = i

teamOrder = [[] for i in range(t)]
lineOrder = []
while True:
    try:
        s = input()
        if s != 'DEQUEUE':
            o, n = s.split()
            n = int(n)
            if len(teamOrder[team[n]]) == 0:
                lineOrder.append(team[n])
            teamOrder[team[n]].append(n)
        else:
            top = lineOrder[0]
            print(teamOrder[top][0])
            teamOrder[top] = teamOrder[top][1:]
            if len(teamOrder[top]) == 0:
                lineOrder = lineOrder[1:]
    except:
        break
