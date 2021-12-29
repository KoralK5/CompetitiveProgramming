f = open('d1.txt').read().split('\n')
n=0
for i in range(1, len(f)-1):
    if int(f[i]) > int(f[i-1]):
        n+=1
print(n)

