num = 10 #전역변수 num

def func():
    num = 20
    #전역변수 값을 바꾼건지?
    #아니면 지역변수 새로 만든건지?
    #지역변수 num을 선언하고 20을 대입
    print(num)#지역변수

func()
print(num)#전역변수

