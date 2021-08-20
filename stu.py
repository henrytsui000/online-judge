import math
def sigmoid(x):
    return 1/(1+math.exp(-x))

def cal(a, b, c):
    return float(a)*0.4+float(b)*0.6+float(c)

x = input()
lst = x.split()
print(cal(*lst))
print(sigmoid(cal(*lst)))
