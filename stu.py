#!/usr/bin/python3
import hashlib
m = hashlib.md5()

def get(i):
    m = hashlib.md5()
    data = str(i)
    m.update(data.encode("utf-8"))
    h = m.hexdigest()
    return h

for i in range(0, 100):
    for j in range(0, 100):
        for k in {"+",'-',"*"}:
            t = str(i)+k+str(j)
            for jj in range(10):
                t = get(t)
                if( t == "b1cab02f274011662eaf895c6791e59e"):
                    print(str(i)+k+str(j))

# for i in range(-1000,100000):
#     t = i
    # for j in range(10):
    #     t = get(t)
    #     if( t == "b1cab02f274011662eaf895c6791e59e"):
    #         print(i)