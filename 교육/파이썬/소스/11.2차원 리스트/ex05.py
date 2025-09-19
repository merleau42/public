list = [
    [10,20], #0행
    [30,40], #1행
    [50,60]  #2행
]   #0열 1열

for i in range(0,3): #행 변화
    for j in range(0,2): #열 변화
        print(list[i][j],end=' ')
    print('')