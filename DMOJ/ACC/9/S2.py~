MOD = 998244353

T = int(input())
for t in range(T):
    n = int(input())
    nums = list(map(int, input().split()))
    a = [[]]
    for i in nums:
        if i == 0:
            a.append([])
        else:
            a[-1].append(i);

    ans = -1
    for vals in a:
        if len(vals) == 0:
            continue

        neg = 0
        for i in vals:
            if i < 0:
                neg += 1
        if neg%2 == 1 and len(vals) > 1:
            idx = 0
            for i in range(len(vals)):
                if vals[i] < 0:
                    idx = i + 1
                    break

            two = 0
            for i in range(idx, len(vals)):
                two += abs(vals[i]) == 2

            if idx != len(vals):
                ans = max(ans, two)

            idx = 0
            for i in range(len(vals)-1,-1,-1):
                if vals[i] < 0:
                    idx = i
                    break

            two = 0
            for i in range(0, idx):
                two += abs(vals[i]) == 2

            if idx != 0:
                ans = max(ans, two)
        elif neg%2 == 0:
            two = 0
            for i in vals:
                two += abs(i)==2

            ans = max(ans, two)

    if ans == -1:
        print(max(nums))
    else:
        print(pow(2, ans, MOD))
