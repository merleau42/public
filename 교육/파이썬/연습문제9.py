#------------ 연습문제 9-1 ~ 9-2
class 인적사항:
	def __init__(self):
		self.age = 0
		self.name = "이름없음"
	def up_age(self):
		self.age += 1
	def get_age(self):
		return self.age
	def set_age(self, AGE):
		self.age = AGE
	def set_name(self, NAME):
		self.name = NAME
	def show_info(self):
		print(minho.age, minho.name, sep = '\t')


minho = 인적사항()
minho.show_info()

minho.set_age(33)
minho.set_name("이민호")
minho.show_info()

minho.up_age()
minho.up_age()
minho.up_age()
minho.show_info()
print()


#------------ 연습문제 9-3
class 영화정보:
	def __init__(self):
		self.제목 = "제목없음"
		self.평점 = 0
		self.러닝타임 = 0

	def set_title(self, _제목):
		self.제목 = _제목
	def set_rating(self, _평점):
		self.평점 = _평점
	def set_duration(self, _러닝타임):
		self.러닝타임 = _러닝타임

	def get_title(self):
		return self.제목
	def get_rating(self):
		return self.평점
	def get_duration(self):
		return self.러닝타임

	def show_info(self):
		print(f'제목: {self.제목}')
		print(f'평점: {self.평점}점')
		print(f'러닝타임: {self.러닝타임}분')
		print()

갯수 = int(input("영화의 갯수는? "))
영화DB = list(range(갯수))

for i in range(갯수):
	print(f'<영화{i+1}>')
	영화 = 영화정보()
	영화.set_title( input("   ㄴ제목은? ") )
	영화.set_rating( input("   ㄴ평점은? ") )
	영화.set_duration( input("   ㄴ러닝타임은? ") )
	영화DB[i] = 영화

print('<<영화 목록>>')
for i in range(갯수):
	영화 = 영화DB[i]
	영화.show_info()
print()

#------------ 연습문제 9-4
class 자동차정보:
	def __init__(self):
		self.모델명 = "모델명없음"
		self.연비 = 0
		self.가격 = 0

	def set_model(self, _모델명):
		self.모델명 = _모델명
	def set_fuel(self, _연비):
		self.연비 = _연비
	def set_price(self, _가격):
		self.가격 = _가격

	def get_model(self):
		return self.모델명
	def get_fuel(self):
		return self.연비
	def get_price(self):
		return self.가격

	def show_info(self):
		print(f'모델명: {self.모델명}')
		print(f'연비: {self.연비}km/L')
		print(f'가격: {self.가격}만원')
		print()

print('<<오빠차>>')
오빠차 = 자동차정보()
오빠차.set_model("1톤 트럭")
오빠차.set_fuel("50")
오빠차.set_price("1000")
오빠차.show_info()
print()


#------------ 연습문제 9-5
class 학생정보:
	def __init__(self):
		self.이름 = "이름없음"
		self.학년 = 0
		self.전공 = "전공없음"

	def set_name(self, _이름):
		self.이름 = _이름
	def set_grade(self, _학년):
		self.학년 = _학년
	def set_major(self, _전공):
		self.전공 = _전공

	def get_name(self):
		return self.이름
	def get_grade(self):
		return self.학년
	def get_major(self):
		return self.전공

	def show_info(self):
		print(f'이름: {self.이름}')
		print(f'학년: {self.학년}학년')
		print(f'전공: {self.전공}')
		print()

print('<<첫사랑 (건축학개론)>>')
첫사랑 = 학생정보()
첫사랑.set_name("수지")
첫사랑.set_grade("4.0")
첫사랑.set_major("건축학과")
첫사랑.show_info()
print()