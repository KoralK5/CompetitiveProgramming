s = input()

S = s.count('S')
M = s.count('M')
L = s.count('L')

SinL = s[:L].count('S')
MinL = s[:L].count('M')
LinL = s[:L].count('L')

SinM = s[L:L+M].count('S')
MinM = s[L:L+M].count('M')
LinM = s[L:L+M].count('L')

SinS = s[L+M:].count('S')
MinS = s[L+M:].count('M')
LinS = s[L+M:].count('L')

ans = 0

# swap S and M
minSM = min(MinS, SinM)
MinS -= minSM
SinM -= minSM
ans += minSM

# swap S and L
minSL = min(LinS, SinL)
LinS -= minSL
SinL -= minSL
ans += minSL

# swap M and L
minML = min(LinM, MinL)
LinM -= minML
MinL -= minML
ans += minML

#still change
still = SinM + SinL + MinS + MinL + LinS + LinM

ans += max(0, still-1)

print(ans)
'''
print(s)
print(' ', 'S', 'M', 'L')
print('S', SinS, MinS, LinS)
print('M', SinM, MinM, LinM)
print('L', SinL, MinL, LinL)
'''
