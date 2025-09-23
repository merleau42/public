list = [
    [10,20,30], # 0행
    [40,50,60], # 1행
   #0열 1열 2열
]
# 2행 3열 2차원 리스트
print(list)
print(list[0][0],end=' ') #0행 0열 - 10
print(list[0][1],end=' ') #0행 1열 - 20
print(list[0][2])         #0행 2열 - 30
print(list[1][0],end=' ') #1행 0열 - 40
print(list[1][1],end=' ') #1행 1열 - 50
print(list[1][2])         #1행 2열 - 60list = [
    [10,20,30], # 0행
    [40,50,60], # 1행
   #0열 1열 2열
]
# 2행 3열 2차원 리스트
for i in range(0,2,1): #행변화
    for j in range(0,3,1): #열변화
        print(list[i][j],end=' ')
    print('')list = [
    [0,0,0], # 0행
    [0,0,0], # 1행
   #0열 1열 2열
]
num=0
# 2행 3열 2차원 리스트
for i in range(0,2,1): #행변화
    for j in range(0,3,1): #열변화
        num=input("입력:")
        num=int(num)
        list[i][j]=num
print(list)list = [
    [10,20], #0행
    [30,40], #1행
    [50,60]  #2행
]   #0열 1열

print(list[0][0],end=' ')
print(list[0][1])
print(list[1][0],end=' ')
print(list[1][1])
print(list[2][0],end=' ')
print(list[2][1])list = [
    [10,20], #0행
    [30,40], #1행
    [50,60]  #2행
]   #0열 1열

for i in range(0,3): #행 변화
    for j in range(0,2): #열 변화
        print(list[i][j],end=' ')
    print('')list = [
    [0,0], #0행
    [0,0], #1행
    [0,0]  #2행
]   #0열 1열
num = 0
for i in range(0,3): #행 변화
    for j in range(0,2): #열 변화
        num = input("입력:")
        num = int(num)
        list[i][j]=num
print(list) #전체 출력tuple = (1,2,3)
print(tuple)

l=list(tuple)#tuple을 리스트로 변환
print(l)
l=list(range(1,4))#range를 리스트로 변환
print(l)
l=list("hello")#문자열을 리스트로 변환
print(l)l = [1,2,3]

t=tuple(l) #리스트를 튜플로 변환
print(t)

t=tuple(range(1,4)) # range를 튜플로 변환
print(t)

t=tuple("hello") # 문자열을 튜플로 변환
print(t)
print(1,2,3, end=' ')
print(4,5,6, end='\n\n\n')
print(7,8,9)

#print는 줄바꿈 문자 기본적으로 내장되어있다.
#\n - 줄바꿈 문자
#end=' ' 원래 기본적으로 내장된 줄바꿈문자가
#적용안되고 그냥 띄어쓰기로 대체됨
#줄바꿈 빠지고 띄어쓰기 한칸 들어간다.
# 백스페이스 왼쪽 역슬래시 \ (역슬래시) , / (정방향)print(1,2,3,end=' m^^m ')
print('')
print(1,2,3,sep=', ')

print(1,2,3,sep=' _ ',end=' m^^m ')
print(1,2,3,sep='@',end='^^')
print('')
print(4,5,6,sep='~',end='!!')
