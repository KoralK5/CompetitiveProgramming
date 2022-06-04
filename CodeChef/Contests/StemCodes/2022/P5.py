def tetra(n):
    num = 0
    for i in range(1, n+1):
        num += i*(i+1)//2
    return num

print(tetra(6))
