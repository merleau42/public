import random

class Person:
	타입 = "사람"
	def __init__(self):
		self.이름 = "없음"
		self.나이 = 0
		self.키 = 0

	def set_name(self, _이름):
		self.이름 = _이름
	def set_age(self, _나이):
		self.나이 = _나이
	def set_height(self, _키):
		self.키 = _키

	def get_name(self):
		return self.이름
	def get_age(self):
		return self.나이
	def get_height(self):
		return self.키

	def show_base(self):
		print(f'타입: {self.타입}')
		print(f'이름: {self.이름}')
		print(f'나이: {self.나이}점')
		print(f'키: {self.키}분')
		print()


class Student(Person):
	타입 = "학생"
	def __init__(self):
		super().__init__()
		self.학년 = 0
		self.전공 = "없음"
		self.성적 = {}
	
	def set_성적(self, 과목명, 점수):
		self.성적[과목명] = 점수
		print("성적이 등록되었습니다")

	def show_info(self):
		print(f'학년: {self.학년}')
		print(f'전공: {self.전공}')
		print(f'성적: {self.성적}')
		print()


class Police(Person):
	타입 = "경찰"
	def __init__(self):
		super().__init__()
		self.계급 = "없음"
		self.총알 = 0
	
	def show_info(self):
		print(f'계급: {self.계급}')
		print(f'총알: {self.총알}')
		print()
	
	def 발포(self):
		if (self.총알 > 0):
			self.총알 -= 1
			print(f'탕!  (총알:{self.총알})')
		else:
			print('총알이 부족합니다')
	
	def 재장전(self):
		if (self.총알 > 0):
			print('아직 총알이 남아있습니다')
		else:
			self.총알 = 5;
			print(f'장전!  (총알:{self.총알})')


class Employee(Person):
	타입 = "직장인"
	def __init__(self):
		super().__init__()
		self.부서 = "없음"
		self.급여 = "없음"
	
	def show_info(self):
		print(f'부서: {self.부서}')
		print(f'급여: {self.급여}')
		print()
	
	def 부서이동(self):
		기존 = self.부서
		self.부서 = ["개발", "영업", "행정", "인사", "기획"][random.randrange(5)]
		print(f'부서 이동: {기존} ----> {self.부서}')
	
	def 급여인상(self):
		기존 = self.급여
		self.급여 += (random.randrange(5) - 1) * 10
		print(f'급여 변경: {기존} ----> {self.급여}')



yuri = Student()

yuri.이름 = "유리"
yuri.학년 = 4
yuri.show_base()

yuri.전공 = "디자인"
yuri.set_성적("2d", 95)
yuri.set_성적("3d", 100)
yuri.show_info()


경찰 = Police()
경찰.show_info()

경찰.재장전()
경찰.발포()
경찰.발포()
경찰.발포()
경찰.발포()
경찰.발포()
경찰.발포()
경찰.재장전()
경찰.발포()
경찰.show_info()


직장인 = Employee()
직장인.부서 = "개발"
직장인.급여 = 200
직장인.show_info()

직장인.부서이동()
직장인.부서이동()
직장인.부서이동()
직장인.급여인상()
직장인.급여인상()
직장인.급여인상()
직장인.show_info()
