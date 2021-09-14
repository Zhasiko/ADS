import math
def gcd(a,b):
    while(a > 0 and b > 0):
        if a > b:
            a = a % b
        else: b = b % a
    return a+b
def points(dx,dz):
    return gcd(dx,dz)+1
x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
print(points(abs(x1-x2),abs(y1-y2)))