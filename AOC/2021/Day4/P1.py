f = open('P.txt').read().split('\n\n')
nums = f[0].split(',')

cards = [[j.split() for j in f[i+1].split('\n')] for i in range(len(f[1:]))]

def win(card):
    for i in card:
        if ''.join(i).count('x') == len(i):
            return i 
    
    for i in list(zip(*card)):
        if ''.join(i).count('x') == len(i):
            return i

    return False

br=False
for num in nums:
    for card in range(len(cards)):
        for i in range(len(cards[card])):
            for j in range(len(cards[card][i])):
                if cards[card][i][j] == num:
                    cards[card][i][j] += 'x'
        op = win(cards[card])
        if op:
            br=True
            break
    if br:
        break
 
s=0
for i in cards[card]:
    for j in i:
        if 'x' not in j: s+=int(j)

print(int(num)*s)
