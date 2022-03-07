from collections import defaultdict
from heapq import heappop, heappush

class FreqStack:
    def __init__(self):
        self.m = defaultdict(int)
        self.h = []
        self.index = 0
        
    def push(self, v: int) -> None:
        self.m[v] += 1
        self.index += 1
        heappush(self.h, (-self.m[v], -self.index, v))
        
    def pop(self) -> int:
        a, b, c = heappop(self.h)
        
        self.m[c] -= 1
        
        return c

stk = FreqStack()
while True:
    try:
        s = input()
        if s != 'pop':
            stk.push(int(s.split()[1]))
        else:
            print(stk.pop())
    except:
        break


