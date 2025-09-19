class AgeInfo:
    def __init__(self):
        self.age = 20
    def get_age(self):
        return self.age

fa = AgeInfo()#AgeInfo클래스로 객체 생성
print(fa.get_age())