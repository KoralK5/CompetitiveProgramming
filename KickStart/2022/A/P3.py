from copy import deepcopy

def recur(s):
    if '?' in s:
        loc = s.index('?')
        
        s0, s1 = deepcopy(s), deepcopy(s)
        
        s0[loc] = '0'
        if recur(s0):
            return True
        
        s1[loc] = '1'
        if recur(s1):
            return True
    else:
        for size in range(5, len(s)):
            for i in range(len(s)-(size-1)):
                if s[i:i+size] == s[i:i+size][::-1]:
                    return False
        return True
    return False
    
for t in range(int(input())):
    print(f'Case #{t+1}:', end=' ')
    n = int(input())
    s = list(input())
    if n < 5:
        print('POSSIBLE')
    else:
        print('POSSIBLE' if recur(s) else 'IMPOSSIBLE')
