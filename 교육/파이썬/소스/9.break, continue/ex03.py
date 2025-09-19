i=1
sum=0

while True:
    sum = sum + i
    if sum > 100:
        print(i,'더했을때의 합,',sum,end=' ')
        break
    i=i+1