import sys
sys.stdin = open('B2_t1.txt', 'r')

def solve():
    n = int(input())
    s = input()
    ones = [len(i) for i in s.split('0') if len(i)]
    zers = [len(i) for i in s.split('1') if len(i)]

    # replace 0s


t = int(input())
for i in range(t):
    solve();

