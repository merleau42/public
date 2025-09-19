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
p_list[1].show_info()