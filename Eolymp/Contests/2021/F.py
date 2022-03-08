G = [0, 0, 0]

def calc(a, b):
    if b == 0:
        G[0] = a
        G[1] = 1
        G[2] = 0;
        return

    calc(b, a%b)

    x = G[1]
    G[0] = G[0]
    G[1] = G[2]
    G[2] = (x - ((a//b)*G[2])); 

while True:
    try:
        a, b = map(int, input().split())
        calc(a, b)
        print(G[1], G[2], G[0])
    except:
        break
