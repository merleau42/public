import random

n1 = random.randrange(1, 20)
n2 = random.randrange(1, 20)
n3 = random.randrange(1, 20)


#------------ 연습문제 3-1
def 비교():
	n1 = int(input("첫번째 정수 입력: "))
	n2 = int(input("두번째 정수 입력: "))
	print (n1 == n2)
# 비교()


#------------ 연습문제 3-2
def 몫과나머지():
	n1 = int(input("첫번째 정수 입력: "))
	n2 = int(input("두번째 정수 입력: "))
	print (f'{n1}을 {n2}으로 나눈 결과는 {n1 / n2}')
	print (f'{n1}을 {n2}으로 나눈 몫은 {n1 // n2}')
	print (f'{n1}을 {n2}으로 나눈 나머지는 {n1 % n2}')
# 몫과나머지()


#------------ 연습문제 3-4
print( f'{n1}>={n2} → {n1>=n2}' )
print( f'{n2}=={n3} → {n2==n3}' )
print( f'({n1}>={n2}) and ({n2}=={n3}) → {(n1>=n2) and (n2==n3)}' )
print()


#------------ 연습문제 3-5
print( f'{n1}!={n2} → {n1!=n2}' )
print( f'{n2}>={n3} → {n2>=n3}' )
print( f'({n1}!={n2}) or ({n2}>={n3}) → {(n1!=n2) or (n2>=n3)}' )
print()


#------------ 연습문제 3-6
print( f'{n1}=={n2} → {n1==n2}' )
print( f'{n2}!={n3} → {n2!=n3}' )
print( f'({n1}=={n2}) or ({n2}!={n3}) → {(n1==n2) or (n2!=n3)}' )
print()


#------------ 연습문제 3-7
print( f'{n1}=={n2} → {n1==n2}' )
print( f'{n2}!={n3} → {n2!=n3}' )
print( f'not( ({n1}=={n2}) or ({n2}!={n3}) ) → {not((n1==n2)or(n2!=n3))}' )
print()


#------------ 연습문제 3-8
print( f'{n1}!={n2} → {n1!=n2}' )
print( f'{n2}=={n3} → {n2==n3}' )
print( f'not( ({n1}!={n2}) and ({n2}=={n3}) ) → {not((n1!=n2)and(n2==n3))}' )
print()


#------------ 연습문제 3-9
print( f'{n1}>={n2} → {n1>=n2}' )
print( f'not({n2}!={n3}) → {not(n2!=n3)}' )
print( f'{n1}>={n2} and not({n2}!={n3}) → {n1>=n2 and not(n2!=n3)}' )
print()


#------------ 연습문제 3-10
print( f'not({n1}=={n2}) → {not(n1==n2)}' )
print( f'not({n2}!={n3}) → {not(n2!=n3)}' )
print( f'not({n1}=={n2}) or not({n2}!={n3}) → {not(n1==n2) or not(n2!=n3)}' )
print()


#------------ 연습문제 3-11 ~ 3-16
def dec_to_bin(num):
	sign = ""
	bin = ""
	if (num < 0):
		num = -num
		sign = "-"
	while(num != 0):
		bin = str(num % 2) + bin
		num = num // 2
	if (num < 0):
		bin = sign + bin
	return bin

print( dec_to_bin(15) )
print( dec_to_bin(24) )
print( dec_to_bin(37) )
print( dec_to_bin(22) )
print( dec_to_bin(97) )
print( dec_to_bin(85) )
print()


#------------ 연습문제 3-17 ~ 3-28
def bits(n):
	return dec_to_bin(n).rjust(10,'0')
print( n1, bits(n1), sep='\t' )
print( n2, bits(n2), sep='\t' )
print( f'{n1}^{n2}', bits(n1^n2), sep='\t' )
print( f'{n1}|{n2}', bits(n1|n2), sep='\t' )
print( f'{n1}&{n2}', bits(n1&n2), sep='\t' )
print()

print( n1, bits(n1), sep='\t' )
print( n2, bits(n2), sep='\t' )
print( f'{n1}>>2', bits(n1>>2), sep='\t' )
print( f'{n1}<<2', bits(n1<<2,), sep='\t' )
print( f'~{n1}', ~n1, sep='\t' )
