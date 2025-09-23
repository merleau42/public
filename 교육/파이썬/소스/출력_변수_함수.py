print("3+5=", 3+5)
print("3-5=", 3-5)
print("3x5=", 3*5)
print("3÷5=", 3/5)

v1 = 25 
#v1 변수를 선언하고 25로 초기화
#v1 변수를 생성하고 25로 대입했다.

v2 = 30
#v2 변수를 선언하고 30으로 초기화
#int v2 = 30; - java style
#java는 생성할 변수의 데이터타입을
#다 지정해야된다.
#python은 그냥 집어넣으면 알아서 해준다.
print(v1+v2)



x = 3 * 50
y = x + 120
z = y / 3
print(z)


x, y = 0, 797
x = y
print(x, y)

def greet():
    print("반갑습니다.")
    print("파이썬의 세계로 오신것을 환영합니다.")

greet()

def greet2(name):
    print("반갑습니다.",name)
    print(name,"님은 파이썬의 세계로 오셨습니다.")

greet2("Everyone")

def introduce(name,age,height):
    print("내 이름은",name,"입니다.")
    print("내 나이는",age, "살 입니다.")
    print("내 키는", height, "cm 입니다.")

introduce("김철수",20,176.6)
def add(n1,n2):
    return n1+n2

def sub(n1,n2):
    return n1-n2

def mul(n1,n2):
    return n1*n2

def div(n1,n2):
    return n1/n2

result=add(3,4)
print(result)

result=sub(3,4)
print(result)

result=mul(3,4)
print(result)

result=div(3,4)
print(result)

def square(x):
    return x*x

result = square(3)
print("3의 제곱:",result)

def stdWeight(height):
    return (height-100)*0.9

result = stdWeight(176.5)
print("표준체중:",result,"kg")