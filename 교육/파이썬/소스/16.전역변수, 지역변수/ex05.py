num = 10 #전역변수 num

def func():
    global  num
    num = 20 #전역변수 값 변경
    print(num)

func()
print(num)#전역변수

