a = 'True, false, true, true, false, false'
a = a.split(', ')
sm = 0
for i in a:
    if i == 'true':
        sm += 1
print(sm)
