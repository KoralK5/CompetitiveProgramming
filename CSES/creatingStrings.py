from itertools import permutations 
p = set(permutations(input()))
print(len(p))
for i in sorted(p):
    print(''.join(i))
