list = [
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
print(list) #전체 출력