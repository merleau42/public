def func(n):
    lv = n+1
    lc = 10 #지역변수 lc
    #여기서 변수 선언한게 되고
    #함수내부에서 변수선언한거니까 지역변수
    print(lv)

func(12)
print(lc) #lc is not defined

