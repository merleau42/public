def func(n):
    lv = n+1
    print(lv)

func(12)

print(n) # n is not defined - 오류
#함수 매개변수가 대표적인 지역변수라서
#매개변수는 함수 내부에서만 사용가능
#지역변수는 함수 밖을 벗어나면 소멸