x = input()
l = x.split()
for i,v in enumerate(l):
    if i==0:
        continue
    elif i==len(l)-1:
        print(v,end=' ')
    else: 
        print(v,l[0],end=' ')