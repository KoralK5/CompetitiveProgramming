def SeatingStudents(arr):
    n = arr[0]
    mp = [1 for i in range(n+1)]
    mp[0] = 0
    for i in arr[1:]:
        mp[i] = 0

    ans = 0
    for i in range(1, n):
        if mp[i] == 1:
            if i%2:
                ans += mp[i+1]

            if i < n-1:
                ans += mp[i+2]

    return ans

# keep this function call here 
print(SeatingStudents(input()))

'''
Input: [6, 4]
Output: 4

Input: [8, 1, 8]
Output: 6

* *
* *
* *
'''
