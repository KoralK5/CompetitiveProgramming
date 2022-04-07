def isPal(n):
    sn = str(n)
    return sn == sn[::-1]

ans = 0
nums = list(map(str, range(10)))
for a1 in nums[1:]:
    for a2 in nums:
        for a3 in nums:
            for b1 in nums[1:]:
                for b2 in nums:
                    for b3 in nums:
                        n1 = int(a1+a2+a3)
                        n2 = int(b1+b2+b3)
                        cur = n1*n2
                        if isPal(cur):
                            ans = max(ans, cur)

print(ans)
