decks = input()

c = decks.index('C')
d = decks.index('D')
h = decks.index('H')
s = decks.index('S')

q1 = decks[c+1:d]
q2 = decks[d+1:h]
q3 = decks[h+1:s]
q4 = decks[s+1:]

def point(x):
    if x=='A':
        return 4
    elif x=='K':
        return 3
    elif x=='Q':
        return 2
    elif x=='J':
        return 1
    else:
        return 0

print('Cards Dealt              Points')

ct = 0
print('Clubs', end='')
c = 0
for i in q1:
    c += point(i)
    print(f' {i}', end='')
i=len(q1)
c += 3*(i==0) + 2*(i==1) + (i==2)
ct+=c
print('\t',c)

print('Diamonds', end='')
c = 0
for i in q2:
    c += point(i)
    print(f' {i}', end='')
i=len(q2)
c += 3*(i==0) + 2*(i==1) + (i==2)
ct+=c
print('\t',c)

print('Hearts', end='')
c = 0
for i in q3:
    c += point(i)
    print(f' {i}', end='')
i=len(q3)
c += 3*(i==0) + 2*(i==1) + (i==2)
ct+=c
print('\t',c)

print('Spades', end='')
c = 0
for i in q4:
    c += point(i)
    print(f' {i}', end='')
i=len(q4)
c += 3*(i==0) + 2*(i==1) + (i==2)
ct+=c
print('\t',c)

print('\t\t\tTotal',ct)
