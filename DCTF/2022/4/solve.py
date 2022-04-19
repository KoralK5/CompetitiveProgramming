from time import sleep

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

text = '0 3 14 -10 -5 1 14 8 6 11 -9 -6 -8 -9 8 1 -3 -13 -8 8 -4 -7 -12 -3 13 -9 5 6 11 9 -10'

for i in text.split():
    print(alphabet[int(i)], end='')
