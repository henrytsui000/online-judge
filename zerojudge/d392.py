while True:
    try:
        s = input()
        l = s.split()
        l = [int(i) for i in l]
        print(sum(l))
    except:
        break