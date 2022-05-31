s = input()
l = 'pusheen'
print(sum([s[i]!=l[i] for i in range(len(l))]))
