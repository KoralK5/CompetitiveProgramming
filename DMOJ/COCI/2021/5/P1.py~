from collections import defaultdict as dd

def score(s):
    scores = dd(int)
    mul = 1
    if s[0].isdigit():
        mul = int(s[0])
        s = s[1:]

    i = 0
    while i < len(s):
        if i < len(s)-1 and s[i+1].isdigit():
            scores[s[i]] += int(s[i+1])
            i += 1
        else:
            scores[s[i]] += 1
        i += 1

    for i in scores:
        scores[i] *= mul

    return scores


n = int(input())
for i in range(n):
    l, r = input().split('->')

    l = l.split('+')
    r = r.split('+')

    lScore = dd(int)
    for i in l:
        nScore = score(i)
        for i in nScore:
            lScore[i] += nScore[i]

    rScore = dd(int)
    for i in r:
        nScore = score(i)
        for i in nScore:
            rScore[i] += nScore[i]

    print('DA' if lScore==rScore else 'NE')

