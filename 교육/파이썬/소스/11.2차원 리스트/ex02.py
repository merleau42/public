list = [
    [10,20,30], # 0행
    [40,50,60], # 1행
   #0열 1열 2열
]
# 2행 3열 2차원 리스트
for i in range(0,2,1): #행변화
    for j in range(0,3,1): #열변화
        print(list[i][j],end=' ')
    print('')