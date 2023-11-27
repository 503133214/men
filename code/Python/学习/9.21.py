import numpy
import math


def f(x):
    result = x * x
    return result


def f1(y):
    result2 = math.exp(y)
    return result2


num = [0.1, 1, 10]
for i in num:
    print("f(", i , ")=", f(i))
    print("f1(", i , ")=", f1(i))
