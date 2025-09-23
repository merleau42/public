for i in [1,2,3,4]:
    print(i)
for i in [1,2,3,4]:
    print(i,end="_")
print("")
for i in [1,2,3,4]:
    print(i,end=",")
print("")
for i in [1, 2, 3, 4]:
    print(i,end=" ")
print("")list = [1,2,3]
result = type(list)
print(result)
print(list)
print(list[0]) #0번째 인덱스
print(list[1]) #1번째 인덱스
print(list[2]) #2번째 인덱스
list = [1,2,3] + [4,5]
print(list)

list = [1,2,3] * 2
print(list)
#인덱싱 연산st = [1,2,3,4,5]
    # 0 1 2 3 4 5 - 인덱스

print(st[0])#1
print(st[4])#5
st = [1,2,3,4,5]
    # 0 1 2 3 4 5 - 인덱스

st[0]=9 #리스트 st의 0번째 값을 9로 변경
st[4]=7 #리스트 st의 4번째 값을 7로 변경
print(st)st = [1,2,3,4,5]
    # 0 1 2 3 4 5 - 인덱스
    #      -3-2-1 - 음수 인덱스
print(st[-1]) # 5
print(st[-2]) # 4st = ['A','B','C','D','E','F']
    #  0   1   2   3   4   5 - 인덱스
    # -6  -5  -4  -3  -2  -1 - 음수 인덱스
print(st[2:5])
#인덱스:2,3,4 출력:C D E
#슬라이싱 연산
#인덱스 2이상 5미만
print(st[1:4])
#인덱스:1,2,3 출력:B C D
print(st[3:5])
#인덱스:3,4 출력:D Est = ['A','B','C','D','E','F']
    #  0   1   2   3   4   5 - 인덱스
    # -6  -5  -4  -3  -2  -1 - 음수 인덱스

st[0:3] = ['K','K','K']
#st[:3] = ['K','K','K']
print(st)st = ['A','B','C','D','E','F']
    #  0   1   2   3   4   5 - 인덱스
    # -6  -5  -4  -3  -2  -1 - 음수 인덱스

st[:] = ['K','K','K','K','K','K']
#0~5까지 전체 범위
print(st)