import random
from string import printable
# from secret import text, mapping

alphabet = "abcdefghijklmnopqrstuvwxyz \n.,{}?_-'"
pool = list(printable[:-6])
print(pool)

def gen_key(alphabet, mapping):
    random.shuffle(pool)
    key = dict()
    for c, n in zip(alphabet, mapping):
        tmp = []
        for i in range(n):
            tmp.append(pool.pop())
        key[c] = tmp
    return key


def encrypt(pt, key):
    enc_text = ""
    for c in text:
        if c in key:
            enc_text += random.choice(key[c])
    return enc_text

mapping = list(range(len(alphabet)))

key = gen_key(alphabet, mapping)
print(key)

# enc_text = encrypt(text.lower(), key)
# print(enc_text)
