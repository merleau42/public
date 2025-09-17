import random

#------------ 연습문제 6-1 ~ 6-5
표본수 = int(input("원소의 갯수: "))

리스트 = []
for i in range(표본수):
	리스트.append( int(input("원소 입력: ")) )

print(f'\n{리스트}')
print(f'총점: {sum(리스트)}')
print(f'평균: {sum(리스트) / 표본수}')

기준 = int(input("\n기준값 입력: "))
필터링 = []
for i in 리스트:
	if (i >= 기준):
		필터링.append(i)

print(f'{필터링}')
print(f'합격자수: {len(필터링)}')
print(f'합격평균: {sum(필터링) / len(필터링)}')

표준체중 = list(map(lambda 키: (키-100)*0.9, 리스트))
print("\n리스트 변환:", 리스트, 표준체중, sep='\n')


#------------ 연습문제 6-6
print("\n원소 삽입:")
이름 = ['김철수', '박태민', '이재용']
print(이름)

이름.insert(2, '신동엽')
print(이름)
print()


#------------ 연습문제 6-7
st = []
for i in range(7):
	print( st )
	st.append(random.randrange(1, 100))
print( st )

while(len(st) != 0):
	print(st)
	st.pop()
print()


#------------ 연습문제 6-8
성적표 = []
for i in range(8):
	성적표.append( "ABCD"[random.randrange(4)] )
print(성적표)
print(f"A의 갯수: {성적표.count('A')}")
print(f"B의 갯수: {성적표.count('B')}")
print(f"C의 갯수: {성적표.count('C')}")
print(f"D의 갯수: {성적표.count('D')}")
print()


#------------ 연습문제 6-9
원문 = input("쉼표가 포함된 문자열 입력: \n")
print(f"ㄴ분할: {원문.split(',')}")
print(f"ㄴ갯수: {len(원문.split(','))}")