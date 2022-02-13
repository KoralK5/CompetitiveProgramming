n, k = map(int, input().split())
s = input().split('1')
l = [len(i) for i in s]
l.sort(reverse=True)

score = 0;
for i in range(k):
    if i >= len(l): break
    score += l[i]

print(score)
