import sys
for line in sys.stdin:
    a,b = line.split()
    if int(a)==0 and int(b)==0:
        break
    result = (int(a) ** int(b))
    print(result)