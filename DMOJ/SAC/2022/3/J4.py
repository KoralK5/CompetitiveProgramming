def frm(x, b): 
    """ 
    Converts given number x, from base 10 to base b  
 
    x -- the number in base 10 
    b -- base to convert 
    """ 
    assert(x >= 0) 
    assert(1< b < 37) 
    r = '' 
    import string 
    while x > 0: 
        r = string.printable[x % b] + r 
        x //= b 
    return r 
 
 
def to(s, b): 
    """ 
    Converts given number s, from base b to base 10 
 
    s -- string representation of number 
    b -- base of given number 
    """ 
    assert(1 < b < 37) 
    return int(s, b) 
 
 
def convert(s, a, b): 
    """ 
    Converts s from base a to base b 
    """ 
    return frm(to(s, a), b) 


for i in range(int(input())):
    b1, n, b2 = map(int, input().split())
    print(convert(str(n), b1, b2))
