def padded_bin(i, width):
    s = bin(i)
    return s[:2] + s[2:].zfill(width)

n, a = map(int, input().split())
b = padded_bin(a, n)[2:]

# first remove the last bit
small = b
idx = -1
for i in range(len(small)):
    if small[i] == '1':
        idx = i
        break;

if i != -1:
    small = small[:i] + '0' + small[i+1:]

large = b
idx = -1
for i in range(len(large)):
    if large[i] == '0':
        idx = i
        break

if i != -1:
    large = large[:i] + '1' + large[i+1:]

print(int(small, 2), int(large, 2))
