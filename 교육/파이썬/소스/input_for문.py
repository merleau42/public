str = input("How Old Are you:")
print(str)num = "12" + "34"
print(num)num1 = input("숫자1 입력:")
num2 = input("숫자2 입력:")

result = num1+num2
print(result)num1 = input("숫자1 입력:")
num2 = input("숫자2 입력:")

num1 = int(num1)
num2 = int(num2)

result = num1+num2
print(result)result = eval("12+34")

print(result)num1 = float("3.14")
num2 = float("4.15")

result = num1+num2
print(result)num1 = 10
num2 = 20

num1 = str(num1)
num2 = str(num2)

result = num1+num2
print(result)for i in [0,1,2]:
    print(i)
    print("Hi~")dan = 7
for i in [1,2,3,4,5,6,7,8,9]:
    print(dan,"x",i,"=",dan*i)
sum = 0

for i in [1,2,3,4,5,6,7,8,9,10]:
    sum = sum + i

print(sum)for i in range(10):#0~9
    print(i, end=' ')
print("")
for i in range(1,10):  # 1~9
    print(i, end=' ')
print("")
for i in range(1,10,2):  # 1,3,5,7,9
    print(i, end=' ')
result = type(3)
print(result)
result = type(3.14)
print(result)
result = type("hello")
print(result)