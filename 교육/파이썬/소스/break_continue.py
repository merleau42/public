i=0
while i<100:
    print(i, end=' ')
    i=i+1
    if i==20:
        break #반복문 탈출i=1
while True:
    print('무한:',i)
    i=i+1i=1
sum=0

while True:
    sum = sum + i
    if sum > 100:
        print(i,'더했을때의 합,',sum,end=' ')
        break
    i=i+1for i in range(1,11):
    if i%2==0:
        continue #밑에 생략하고 반복문 처음으로
    print(i, end=' ')