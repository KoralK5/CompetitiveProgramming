from collections import defaultdict as dd
import sys
sys.setrecursionlimit(10**6)

graph = dd(list)
visited = set()
count = 0

def small(loc):
    return loc==loc.lower()

def dfs(node):
    global count

    if node == 'end':
        count += 1
        return

    elif small(node):
        if node in visited:
            return
        else:
            visited.add(node)

    for neigh in graph[node]:
        if neigh != 'start':
            dfs(neigh)

    if small(node):
        visited.remove(node)

def solve(f):
    global count, graph, visited
    graph, visited, count = dd(list), set(), 0
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

