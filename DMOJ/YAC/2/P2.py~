def inp(l, r):
    print('?', l, r)
    return int(input())

# max value is probably 3 for all n > 3
n = int(input())
x3 = inp(1, 3)
x2 = inp(2, 3)

nums = [x3^x2]
for i in range(1, n):
    val = inp(i, i+1)
    nums.append(nums[-1]^val)

print('!', ' '.join(map(str, nums)))
