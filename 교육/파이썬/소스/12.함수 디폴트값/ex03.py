def func(s):
    s[0]=10
    #함수 내부에서 넘긴 리스트의 값을 변경할수있다.

st=[1,2,3]
func(st)

print(st)