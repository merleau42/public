from 연습문제1 import 덧셈, 뺄셈, 곱셈, 나눗셈, 평균체중
PI = 3.14

#------------ 연습문제 2-1
def 입력1():
	num1 = int(input("첫번째 정수 입력: "))
	num2 = int(input("두번째 정수 입력: "))
	print( 덧셈(num1, num2) )
	print( 뺄셈(num1, num2) )
	print( 곱셈(num1, num2) )
	print( 나눗셈(num1, num2) )


#------------ 연습문제 2-2
def 입력2():
	키 = float(input("신장(cm) 입력: "))
	print( 평균체중(키) )


#------------ 연습문제 2-3
def 입력3():
	r = float(input("반지름 입력: "))
	print( f"원의 둘레는 {2 * PI * r}" )


#------------ 연습문제 2-4
def 입력4():
	r = float(input("반지름 입력: "))
	print( f"원의 넓이는 {PI * r**2}" )


#------------ 연습문제 2-5
def 구간합():
	시작 = int(input("정수 시작 입력: "))
	끝 = int(input("정수 끝 입력:"))
	스텝 = int(input("스텝 입력:"))
	print( sum(range(시작, 끝+1, 스텝)) )


#------------ 연습문제 2-6
def 구구단():
	단 = int(input("몇단을 출력할까요: "))
	for i in range(2,10):
		print(f'{단} x {i} = {단*i}')


#------------ 연습문제 2-10
for i in range(1,10,2):
	print(i, end=' ')
print()


#------------ 연습문제 2-11
for i in range(2,11,2):
	print(i, end=' ')
print()


#------------ 연습문제 2-12
for i in range(1,14,3):
	print(i, end=' ')
print()


#------------ 연습문제 2-13
for i in range(10,1, -2):
	print(i, end=' ')
print()


#------------ 연습문제 2-14
for i in range(9,0, -2):
	print(i, end=' ')
print()


#------------ 실행