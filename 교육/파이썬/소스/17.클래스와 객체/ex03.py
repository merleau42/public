class AgeInfo:
    def __init__(self):
        self.age = 0
    def up_age(self):
        self.age += 1
    def get_age(self):
        return self.age

def main():
    fa = AgeInfo()
    mo = AgeInfo()
    me = AgeInfo()
    fa.age=39
    mo.age=35
    me.age=12
    s = fa.get_age()+mo.get_age()+me.get_age()
    print("가족 나이 합:",s)
main()