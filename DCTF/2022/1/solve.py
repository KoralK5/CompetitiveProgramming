from collections import defaultdict as dd

freq = dd(int)
f = open('ct.txt', 'r').read()
for i in f:
    freq[i] += 1

vals = []
for i in freq:
    vals.append((freq[i], i))

vals.sort(reverse=True)
for i in vals:
    print(i[0], i[1])
