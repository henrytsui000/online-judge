ls = [20,28,47,56,80,82,113,163,175,205,216,224,237]
cnt = -1
ch = 'A'
for i in ls:
    m, h = 30, 18
    m += i
    while m >= 60:
        m -= 60
        h += 1
    cnt += 1
    print (f'{chr(ord(ch)+cnt)} : hour:{h}:{m}')

