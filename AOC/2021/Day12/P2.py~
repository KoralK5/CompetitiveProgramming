from collections import defaultdict as dd
import sys
sys.setrecursionlimit(10**6)

graph = dd(list)
visited = dd(int)
count = 0

def small(loc):
    return loc==loc.lower()

def dfs(node):
    global count

    if node == 'end':
        count += 1
        return

    elif small(node):
        visited[node] += 1
        mult = 0
        for cave in visited:
            mult += visited[cave]>1

            if visited[cave] > 2:
                visited[node] -= 1
                return

        if mult > 1:
            visited[node] -= 1
            return

    for neigh in graph[node]:
        if neigh != 'start':
            dfs(neigh)

    if small(node):
        visited[node] -= 1

def solve(f):
    global count, graph, visited
    graph, visited, count = dd(list), dd(int), 0
    d = open(f'{f}.txt').read().split('\n')[:-1]
    for path in d:
        path = path.split('-')
        graph[path[0]].append(path[1])
        graph[path[1]].append(path[0])

    dfs('start')
    print(count)

solve('T')
solve('T_2')
solve('P')
