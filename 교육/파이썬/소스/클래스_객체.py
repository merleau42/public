class AgeInfo:
    def __init__(self):
        self.age = 20
    def get_age(self):
        return self.age

fa = AgeInfo()#AgeInfo클래스로 객체 생성
print(fa.get_age())class Movie:
    def __init__(self): #생성자
        self.title='아바타' #멤버변수
        self.rating=9.3 #멤버변수
        self.running=130 #멤버변수
    def show_info(self): #정보출력함수
        print("제목:",self.title)
        print("평점:", self.rating)
        print("러닝타임:", self.running)

m = Movie()#Movie객체 생성
m.show_info()#객체내부의 함수 호출class AgeInfo:
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
main()class Person:
    def __init__(self,name,age):
       self.name=name
       self.age=age

    def get_name(self):
       return self.name

    def set_name(self,name):
       self.name=name

    def get_age(self):
       return self.age

    def set_age(self,age):
       self.age=age

    def show_info(self):
       print("이름:",self.name)
       print("나이:",self.age)

p1 = Person("이민호",20)
p2 = Person("정채연",21)
p1.show_info()
p2.show_info()class Student:
    def __init__(self, name, grade, major):
        print("생성자 호출")
        self.name = name
        self.grade = grade
        self.major = major

    def get_name(self):
        return self.name
    def set_name(self,name):
        self.name=name
    def get_grade(self):
        return self.grade
    def set_grade(self,grade):
        self.grade=grade
    def get_major(self):
        return self.major
    def set_major(self,major):
        self.major=major
    def show_info(self):
        print("이름:", self.name)
        print("학년:", self.grade)
        print("전공:", self.major)


std1 = Student("이민호", 1, "컴퓨터공학")
std2 = Student("정채연", 2, "전자공학")
std1.show_info()
std2.show_info()
class Person:
    def __init__(self,name,age):
       self.name=name
       self.age=age

    def get_name(self):
       return self.name

    def set_name(self,name):
       self.name=name

    def get_age(self):
       return self.age

    def set_age(self,age):
       self.age=age

    def show_info(self):
       print("이름:",self.name)
       print("나이:",self.age)

p_list=[ Person("이민호",20) , Person("정채연",21) ]
p_list[0].show_info()
p_list[1].show_info()class Person:
    def __init__(self,name,age):
       self.name=name
       self.age=age

    def get_name(self):
       return self.name

    def set_name(self,name):
       self.name=name

    def get_age(self):
       return self.age

    def set_age(self,age):
       self.age=age

    def show_info(self):
       print("이름:",self.name)
       print("나이:",self.age)

p_list=[ Person("이민호",20) , Person("정채연",21) ]
for obj in p_list:
     obj.show_info()n = 1000

print(type(n))
print(n.bit_length())

n = 4
print(n.bit_length())f = 3.14
print(type(f))
print(f.is_integer())s = "hello"
print(type(s))
print(s.index("e"))r = True

print(type(r))
print(r.bit_length())