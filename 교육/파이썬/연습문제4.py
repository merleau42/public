# from 연습문제2 import 구간합
import random

n1 = random.randrange(1, 51)
n2 = random.randrange(n1, 101)

print(f'시작값 ~ 끝값:  {n1} ~ {n2}')


#------------ 연습문제 4-1
print(f"\n{n1}세:", end=' ')
if (n1 >= 19):
	print("성인")
else:
	print("미성년자")


#------------ 연습문제 4-2
# print( 구간합(1, 100) )


#------------ 연습문제 4-3
print(f'\n짝수(~{n2}):', end=' ')
for i in range(n1, n2 + 1):
	if (i % 2 == 0):
		print( i, end=' ' )


#------------ 연습문제 4-4
print(f'\n\n홀수(~{n2}):', end=' ')
for i in range(n1, n2 + 1):
	if (i % 2 != 0):
		print( i, end=' ' )


#------------ 연습문제 4-6 ~ 4-9
print(f'\n\n{n1} 분석')
def 약수(n):
	ret=[]
	for i in range(1, n+1):
		if (n % i == 0):
			ret.append(i)
	return ret
print(f'ㄴ약수: {약수(n1)}')
print(f'ㄴ갯수: {len(약수(n1))}')
print(f'ㄴ진약수의 합: {sum(약수(n1)[:-1])} (= {" + ".join(map(str,약수(n1)[:-1]))})')

if (sum(약수(n1)[:-1]) == n1):
	print("ㄴ완전수: o")
else:
	print("ㄴ완전수: x")

if(n1 > 1 and len(약수(n1)) <= 2):
	print("ㄴ소수: o")
else:
	print("ㄴ소수: x")


#------------ 연습문제 4-10 ~ 4-13
def 최대공약수(a, b):
	if (b):
		return 최대공약수(b, a % b)
	return a

def 최소공배수(a, b):
	return a * b / 최대공약수(a, b)

print(f'\n{n1}, {n2}')
print(f'ㄴ최대공약수: {최대공약수(n1, n2)}')
print(f'ㄴ최소공배수: {int(최소공배수(n1, n2))}')

#------------ 연습문제 4-5, 4-14
print(f'\n짝수단:')
si = 0
for i in range(9, 1, -1):
	if (i % 2 == 0):
		sj = 0
		for j in range(1, 10):
			print(f'{i} x {j} = {i*j}')
			sj += i*j
		print(f'{i}단의 합: {sj}')
		si += sj
print(f'모든 단의 합: {si}')


#------------ 연습문제 4-18 ~ 4-19
print(f'\n1 ~ 1000 사이의 완전수:')
for i in range(1, 1001):
	진약수 = 약수(i)[:-1]
	if (sum(진약수) == i):
		print(i)


#------------ 연습문제 4-18 ~ 4-19
print(f'\n1 ~ 1000 사이의 소수:')
def isPrime(n):
	for i in range(2,n):
		if (n % i == 0):
			return False
	return True
for i in range(1, 1000):
	if (isPrime(i)):
		print(i, end=' ')
print()


#------------ 연습문제 4-20
print(f'\n나이별 구분:')
for i in range(1, 101):
	성년 = "미성년자" if (i<20) else "성인"
	if (i<8):
		구분 = "미취학"
	elif (i<20):
		구분 = "취학"
	elif (i<65):
		구분 = "일반"
	else:
		구분 = "고령"
	print(f'{i}살-{성년}-{구분}')
