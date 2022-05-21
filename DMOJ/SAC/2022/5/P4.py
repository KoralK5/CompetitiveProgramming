def merge_intervals(intervals):
    x = intervals[::-1]
    sorted_intervals = sorted(intervals, key=lambda x: x[0])
    interval_index = 0
    #print(sorted_intervals)
    for  i in sorted_intervals:

        if i[0] > sorted_intervals[interval_index][1]:
            interval_index += 1
            sorted_intervals[interval_index] = i
        else:
            sorted_intervals[interval_index] = [sorted_intervals[interval_index][0], i[1]]
    #print(sorted_intervals)
    return sorted_intervals[:interval_index+1]

n, q = map(int, input().split())

vals = []
for i in range(n):
    l, r = map(int, input().split())
    vals.append([l, r])

nVals = merge_intervals(vals)
print(nVals)
