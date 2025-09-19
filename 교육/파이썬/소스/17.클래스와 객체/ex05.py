class Student:
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
