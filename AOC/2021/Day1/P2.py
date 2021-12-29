f = open('P.txt').read().split('\n')
s=[]
for i in range(2, len(f)-1):
    s.append(int(f[i])+int(f[i-1])+int(f[i-2]))

n=0
for i in range(1,len(s)):
    n+=s[i]>s[i-1]

print(n)
