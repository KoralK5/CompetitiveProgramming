def inp(l, r):
    print('?', l, r)
    return int(input())

# get edges
n = int(input())

nums = [inp(1, n)]
ans = []

for i in range(2, n-2):
    val = inp(i, n)
    nums.append(val)
    ans.append(nums[-2]^nums[-1])

print('!', ' '.join(map(str, nums)))
