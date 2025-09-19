from circle import ar_circle as ac
from circle import ci_circle as cc

def main():
    r = float(input("반지름 입력:"))
    ar = ac(r)
    print("넓이:",ar)
    ci = cc(r)
    print("둘레:", ci)
main()