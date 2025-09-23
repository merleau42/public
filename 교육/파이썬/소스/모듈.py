PI = 3.14

def ar_circle(rad):
    return rad*rad*PI

def ci_circle(rad):
    return rad*2*PIimport circle

def main():
    r = float(input("반지름 입력:"))
    ar = circle.ar_circle(r)
    print("넓이:",ar)
    ci = circle.ci_circle(r)
    print("둘레:", ci)
main()from circle import ar_circle, ci_circle

def main():
    r = float(input("반지름 입력:"))
    ar = ar_circle(r)
    print("넓이:",ar)
    ci = ci_circle(r)
    print("둘레:", ci)
main()from circle import ar_circle as ac
from circle import ci_circle as cc

def main():
    r = float(input("반지름 입력:"))
    ar = ac(r)
    print("넓이:",ar)
    ci = cc(r)
    print("둘레:", ci)
main()import math

result=math.fabs(-10)
print(result)

result=math.sqrt(2)#square root-2제곱근
print(result)

import random

for i in range(1,11):
    num = random.random()
    print(num)import random

for i in range(1,11):
    num = random.randint(1,3)
    print(num)