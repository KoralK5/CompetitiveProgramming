words = '''
	? a	? ka	? na	? ha	? ma	? ra
	? i	? ki	? ni	? hi	? mi	? ri
	? u	? ku	? nu	? fu	? mu	? ru
	? e	? ke	? ne	? he	? me	? re
	? o	? ko	? no	? ho	? mo	? ro
'''

words = words.split()
print(words)
lst = []
for i in words:
    if i != '?':
        lst.append(i)
print(lst)
