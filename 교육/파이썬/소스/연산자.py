num1 = 9
num2 = 2
print("덧셈결과:",num1+num2)
print("뺄셈결과:",num1-num2)
print("곱셈결과:",num1*num2)
print("나눗셈결과:",num1/num2)
print("나머지결과:",num1%num2)
print("거듭제곱결과:",num1**num2)
print("몫:",num1//num2)
num1 = 10

num1 += 10
#num1 = num1 + 10
print(num1)num1 = 10

result = num1>=10
print(result)
result = num1>=15
print(result)
num1 = 20

result = (num1 < 10)
print(result)

result = (num1 > 10)
print(result)num1 = 20

result = (num1==10)
print(result)

result = (num1!=10)
print(result)print(False and False)
print(False and True)
print(True and False)
print(True and True)
print(False or False)
print(False or True)
print(True or False)
print(True or True)
print(not True)
print(not False)
num1 = 2
num2 = 6
num3 = 5

result = (num1 == num2) or (num2 >= num3)
print(result)num1 = 5 # 00000000 00000000 00000000 00000101
num2 = 3 # 00000000 00000000 00000000 00000011
result = num1 & num2
print(result)num1 = 5 # 00000000 00000000 00000000 00000101
num2 = 3 # 00000000 00000000 00000000 00000011
result = num1 | num2
print(result)num1 = 5 # 00000000 00000000 00000000 00000101
num2 = 3 # 00000000 00000000 00000000 00000011
result = num1 ^ num2
print(result)