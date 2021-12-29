def main():
    input()
    f = input().split()
    s = input().split()
    p = {}

    for i in range(len(f)):
        if f[i] == s[i]:
            print('bad')
            return

        elif s[i] not in p:
            p[s[i]] = f[i]

        elif p[s[i]] != f[i]:
                print('bad')
                return
    print('good')

main()
