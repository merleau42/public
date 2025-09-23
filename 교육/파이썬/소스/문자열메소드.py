result = type(True)
print(result)

result = type(False)
print(result)
def sum():
    print('sum 함수')

def main():
    print('main실행')
    sum()

main()
num = int(input("2의배수이면서 3의배수인 수 입력"))
if num%2==0:
    if num%3==0:
        print("OK!")
    else:
        print("NO!")
else:
    print("NO!")
num = int(input("2의배수이면서 3의배수인 수 입력"))
if num%2==0 and num%3==0:
    print("OK!")
else:
    print("NO!")st1="1234"
st2="OneTwoThree"

result = st1.isdigit()
print(result)

result = st2.isdigit()
print(result)st1="1234"
st2="OneTwoThree"

result = st1.isalpha()
print(result)

result = st2.isalpha()
print(result)str = "Supersprint"

result=str.startswith("Super")
print(result)

result=str.endswith("int")
print(result)
pnum = input("스마트폰 번호 입력")

if pnum.isdigit() and pnum.startswith("010"):
    print("정상적인 입력")
else:
    print("정상적이지 않은 입력")
s = "Tomato spaghetti"
#    012
result=s.find("ghe")
print(result)

result=s.find("mat")
print(result)

result=s.find("aaa")
print(result)s = "Tomato spaghetti"

if s.find("ghe") != -1:
    print("있습니다.")
else:
    print("없습니다.")
result = 3 in [1,2,3]
print(result)

result = 4 in [1,2,3]
print(result)result = 3 not in [1,2,3]
print(result)

result = 4 not in [1,2,3]
print(result)sum = 0
for i in range(1,11):
    sum = sum + i
print("sum=",sum,end=' ')
i=1         #초기식
sum=0       #합저장할 변수

while i<11: #i가 11보다 작은동안 반복
    sum = sum+i #sum+i값을 sum변수에 저장
    i = i+1 #i값 1증가
print("sum=",sum,end=' ')#반복문끝나고 합출력