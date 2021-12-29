import matplotlib.pyplot as plt 

n = int(input())
x, y = [], []
for i in range(n):
    x.append(float(input()))
    y.append(float(input()))

plt.figsize=(1000,1000)
plt.scatter(x, y)
plt.savefig('S5.png', bbox_inches='tight')
