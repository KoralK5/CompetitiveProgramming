val = 'YesYes'*100

res = ''
for i in range(int(input())):
    s = input()
    res += 'YES\n' if s in val else 'NO\n'

print(res)
