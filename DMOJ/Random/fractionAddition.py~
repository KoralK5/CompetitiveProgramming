a = int(input())
b = int(input())

for i in range(2, min(a,b)+1):
    if a%i==0 and b%i==0:
        a//=i
        b//=i

if a == 0:
    print(0)
elif b == 1:
    print(a)
else:
    rem = a//b
    if rem:
        print(f'{rem} {a%b}/{b}')
    else:
        print(f'{a}/{b}')

