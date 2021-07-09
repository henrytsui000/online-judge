import sys
for line in sys.stdin:
    count = 0
    word = 1
    for i in range(len(line)):
        if line[i].isalpha():
            if word == 1:
                count += 1
                word = 0
        else:
            word = 1
    print(count)