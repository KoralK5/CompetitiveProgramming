ip=lambda x: int(input()) if x else input()
l=range(ip(1))
a=[list(map(int,ip(0).split()))for i in l]
print(abs(sum((a[i-1][0]+a[i][0])*(a[i-1][1]-a[i][1])for i in l)))
