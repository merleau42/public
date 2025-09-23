#------------ 연습문제 10-1
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

	def show_info(self):
		print(f'이름: {self.이름}')
		print(f'나이: {self.나이}점')
		print(f'키: {self.키}분')
		print()


#------------ 연습문제 10-2
class Movie:
	타입 = "영화"
	def __init__(self):
		self.제목 = "없음"
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


#------------ 연습문제 10-3
class Car:
	타입 = "자동차"
	def __init__(self):
		self.모델명 = "없음"
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


#------------ 연습문제 10-4
class Student:
	타입 = "학생"
	def __init__(self):
		self.이름 = "없음"
		self.학년 = 0
		self.전공 = "없음"

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


#------------ 객체 리스트 생성 및 출력
def 객체매니저(클래스, 갯수 = None):
	print(f'------- {클래스.타입} 클래스의 객체매니저를 실행합니다')
	if (갯수 == None):
		갯수 = int(input("인스턴스의 갯수는? "))
	print(f'{갯수}개의 {클래스.타입} 인스턴스를 생성하려 합니다')
	리스트 = list(range(갯수))

	for i in range(갯수):
		print(f'<{클래스.타입}{i+1}>')
		인스턴스 = 클래스()
		for 변수 in [멤버.split('_')[1] for 멤버 in dir(클래스) if 'set_' in 멤버]:
			getattr(인스턴스, f'set_{변수}')( input(f"   ㄴ{변수}는? ") )
		리스트[i] = 인스턴스
	
	return 리스트

영화DB = 객체매니저(Movie)
for 영화 in 영화DB:
	영화.show_info()

명부 = 객체매니저(Person)
for 사람 in 명부:
	사람.show_info()

학생부 = 객체매니저(Student)
for 학생 in 학생부:
	학생.show_info()

주차장 = 객체매니저(Car)
for 차량 in 주차장:
	차량.show_info()
