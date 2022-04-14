from time import sleep

print([37, 45, 46, 30])
for i in range(10):
    for j in range(10):
        for k in range(10):
            for l in range(10):
                val = i*37 + j*45 + k*46 + l*30
                if val == 232:
                    print(i, j, k, l)
