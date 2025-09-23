class Account:
	타입 = "계좌"
	def __init__(self, _이름="없음", _번호="", _비밀="", _잔고=0):
		self.이름 = _이름
		self.번호 = _번호
		self.비밀 = _비밀
		self.잔고 = _잔고

	def get_이름(self):
		return self.이름
	def get_번호(self):
		return self.번호
	def get_비밀(self):
		return self.비밀
	def get_잔고(self):
		return self.잔고
	def get_all(self):
		for 변수 in [멤버.split('_')[1] for 멤버 in dir(self) if 'set_' in 멤버]:
			print(f'{변수}: {getattr(self, 변수)}')

	def set_이름(self, _이름):
		self.이름 = _이름
	def set_번호(self, _번호):
		self.번호 = _번호
	def set_비밀(self, _비밀):
		self.비밀 = _비밀
	def set_잔고(self, _잔고):
		self.잔고 = _잔고

	def 계좌정보(self):
		마스크 = self.이름[0] + '*' * (len(self.이름)-2) + self.이름[-1]
		print(f"이름: {마스크}\n계좌: {self.번호}\n잔고: {self.잔고}원")

	def 입금(self):
		입금액 = input('입금할 금액 (원): ')
		if (not 입금액.isdigit() and int(입금액) < 1):
			print("1 이상의 숫자만 입력해주세요")
			return False
		입금액 = int(입금액)
		self.잔고 += 입금액
		print(f">> {입금액}원 입금 완료!")
		print(f">> 잔고: {self.잔고}")
		return True

	def 출금(self):
		출금액 = input('출금할 금액 (원): ')
		if (not 출금액.isdigit() and int(출금액) < 1):
			print("1 이상의 숫자만 입력해주세요")
			return False
		출금액 = int(출금액)
		if (self.잔고 < 출금액):
			print("잔액 부족으로 출금 불가!")
			return False
		self.잔고 -= 출금액
		print(f">> {출금액}원 출금 완료!")
		print(f">> 잔고: {self.잔고}")
		return True


def 계좌관리(acc):
	while True:
		print('===== 메뉴 =====')
		메뉴 = input('1.입금\n2.출금\n3.계좌정보조회\n4.종료\n>> ')
		print()
		if (메뉴 == '1'):
			acc.입금()
		elif (메뉴 == '2'):
			acc.출금()
		elif (메뉴 == '3'):
			acc.계좌정보()
		elif (메뉴 == '4'):
			print("계좌 관리 프로그램을 종료합니다")
			break
		else:
			print("1번부터 4번까지 입력해주세요")
		print("\n")


def 객체매니저(클래스, 갯수 = None):
	print(f'------- {클래스.타입} 클래스의 객체매니저를 실행합니다')
	if (갯수 == None):
		갯수 = int(input("인스턴스의 갯수는? "))
	print(f'{클래스.타입} {갯수}개의 인스턴스를 생성하려 합니다')
	리스트 = list(range(갯수))

	for i in range(갯수):
		print(f'<{클래스.타입}{i+1}>')
		인스턴스 = 클래스()
		for 변수 in [멤버.split('_')[1] for 멤버 in dir(클래스) if 'set_' in 멤버]:
			getattr(인스턴스, f'set_{변수}')( input(f"   ㄴ{변수}는? ") )
		리스트[i] = 인스턴스
	
	return 리스트


계좌목록 = 객체매니저( Account )

for 계좌 in 계좌목록:
	계좌.계좌정보()