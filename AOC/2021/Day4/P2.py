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
    card=0
    while card < len(cards):
        for i in range(len(cards[card])):
            for j in range(len(cards[card][i])):
                if cards[card][i][j] == num:
                    cards[card][i][j] += 'x'
        if win(cards[card]):
            cards.pop(card)
        else:
            card+=1
        if len(cards) == 1:
            last=cards[0]
            il = nums.index(num)
            br=True
            break
    if br: break

for n in range(len(nums)):
    if win(last):
        count=0
        for i in last: 
            for j in i: 
                if 'x' not in j:
                    count += int(j)
        print(count*int(nums[n-1]))
        break
    else:
        for i in range(len(last)):
            for j in range(len(last[i])):
                if last[i][j] == nums[n]:
                    last[i][j] += 'x'

