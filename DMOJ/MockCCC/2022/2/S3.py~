def findnth(string, substring, n):
    if string.count(substring) < n: return -1
    return len(string) - len(string.split(substring, n)[-1]) - len(substring) + 1

s = input()
for _ in range(int(input())):
    t, k = input().split()
    print(findnth(s, t, int(k)))
