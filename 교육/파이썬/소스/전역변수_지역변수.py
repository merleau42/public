def func(n):
    lv = n+1
    print(lv)

func(12)

print(n) # n is not defined - 오류
#함수 매개변수가 대표적인 지역변수라서
#매개변수는 함수 내부에서만 사용가능
#지역변수는 함수 밖을 벗어나면 소멸def func(n):
    lv = n+1
    lc = 10 #지역변수 lc
    #여기서 변수 선언한게 되고
    #함수내부에서 변수선언한거니까 지역변수
    print(lv)

func(12)
print(lc) #lc is not defined

lc = 10 #전역변수 lc

def func(n):
    lv = n+1
    print(lv)

func(12)
print(lc)

num = 10 #전역변수 num

def func():
    num = 20
    #전역변수 값을 바꾼건지?
    #아니면 지역변수 새로 만든건지?
    #지역변수 num을 선언하고 20을 대입
    print(num)#지역변수

func()
print(num)#전역변수

num = 10 #전역변수 num

def func():
    global  num
    num = 20 #전역변수 값 변경
    print(num)

func()
print(num)#전역변수

