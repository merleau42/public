lst = [1,2,3]
print(lst[3])

#IndexError: list index out of range
#리스트 인덱스가 범위를 넘어갔다.
#인덱스 0, 1, 2까지인데 3을써서 범위가넘어감print(3+"coffee")
#TypeError: unsupported operand type(s)
#for +: 'int' and 'str'
#타입오류: 지원되지않는 피연산자 타입
#+를 위한: 정수와 문자열
#+는 정수와 문자열을 피연산자로 가질수없다.print("3"+"coffee")num = 3/0
print(num)
age = int(input("나이를 입력하세요:"))
print(age)try:
    age = int(input("나이를 입력하세요:"))
    print("나이:",age)
except ValueError:
    print("입력이 잘못되었습니다.")try: #예외가 발생할만한 코드를 적는다
    age = int(input("나이를 입력하세요:"))
    print("나이:",age)
except ValueError: #ValueError타입 오류면 여기로
    print("입력이 잘못되었습니다.")while True:
    try: #예외가 발생할만한 코드를 적는다
        age = int(input("나이를 입력하세요:"))
        print("나이:",age)
        break
    except ValueError: #ValueError타입 오류면 여기로
        print("입력이 잘못되었습니다.")

# 정수로 변환안되는 문자열 넣으면 ("스물", "스물하나")
# 계속 입력이 잘못되었습니다.
# "20"을 입력하면 변환되고 나이출력하고 break로 종료while True:
    bread=10
    try:
        people = int(input("몇명?"))
        print("1인당 빵의수:",bread/people)
        print("맛있게 드십시오.")
        break
    except ValueError:
        print("입력이 잘못되었습니다.")
    except ZeroDivisionError:
        print("0으로 나눌수 없습니다.")while True:
    bread=10
    try:
        people = int(input("몇명?"))
        print("1인당 빵의수:",bread/people)
        print("맛있게 드십시오.")
        break
    except ValueError as msg:
        print("입력이 잘못되었습니다.")
        print(msg)
    except ZeroDivisionError as msg:
        print("0으로 나눌수 없습니다.")
        print(msg)while True:
    bread=10
    try:
        people = int(input("몇명?"))
        print("1인당 빵의수:",bread/people)
        print("맛있게 드십시오.")
        break
    except ValueError as msg:
        print("입력이 잘못되었습니다.")
        print(msg)
    except ZeroDivisionError as msg:
        print("0으로 나눌수 없습니다.")
        print(msg)
    finally:
        print("finally")