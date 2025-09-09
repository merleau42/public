for i in range(2,10):
	for j in range(1,10):
		print(f"{i} x {j} = {i*j}")

PI = 3.14

def add(a,b):
	return a+b
def sub(a,b):
	return a-b
def mul(a,b):
	return a*b
def div(a,b):
	return a/b	

def 원둘레(r):
	return 2*PI*r

def 원넓이(r):
	return PI*r**2

def 연속합(시작,끝):
	sum=0
	for i in range(시작,끝+1):
		sum += i
	return sum


def 표준체중(키):
	ret = 0
	if 키>160:
		ret = (키-100)*0.9
	elif 키>150:
		ret = (키-150)/2 + 50
	else:
		ret = 키-100
	return ret

print( 표준체중(170) )
print( 연속합(5,9) )
