list = [
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
print(list)