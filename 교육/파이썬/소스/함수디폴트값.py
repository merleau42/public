def who_are_you(name, age=0):
    print("이름:", name)
    print("나이:",age)

who_are_you("김철수")#age에 값을지정안해서 디폴트값0으로
who_are_you("이민호",29)def who_are_you(name="익명사용자", age=0):
    print("이름:", name)
    print("나이:",age)

who_are_you()#값을 하나도 안넘겨서 둘다 디폴트값
who_are_you("김철수")#age에 값을지정안해서 디폴트값0으로
who_are_you("이민호",29)def func(s):
    s[0]=10
    #함수 내부에서 넘긴 리스트의 값을 변경할수있다.

st=[1,2,3]
func(st)

print(st)