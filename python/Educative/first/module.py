import math
def greetF(name):
    print(f"Hello, {name}!")

def findGCD(a, b):
    while b:
        a, b = b, a % b
    return a

def findGCD_builtin(a, b):
    return math.gcd(a, b)

def calculatesSinCosTan(x):
    sin_x = math.sin(x)
    cos_x = math.cos(x)
    tan_x = math.tan(x)
    return sin_x, cos_x, tan_x

def findmaximum(x, y):
    max2 = 0
    if(x>y):
        max2 = x
    else:
        max2 = y
    return max2

def isDivisible(x, y):
    if(x % y == 0):
        return True
    else:
        return False


