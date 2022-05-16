n=int(input());print(sum([i*(n%i==0) for i in range(1,n+1)]))
