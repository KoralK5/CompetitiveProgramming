n = int(input())
s = [int(i) for i in input()]
for i in range(n-1):
    if s[i] < s[i+1]:
        s[i], s[i+1] = s[i+1], s[i]
        break
print(''.join(map(str, s)))
