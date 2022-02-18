s = input()
cur = ''
for i in range(len(s)):
    if s[i].isdigit():
        print(cur[:-1], 'tighten' if cur[-1]=='+' else 'loosen', s[i])
        cur = ''
    else:
        cur += s[i]
