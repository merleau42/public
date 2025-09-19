while True:
    bread=10
    try:
        people = int(input("몇명?"))
        print("1인당 빵의수:",bread/people)
        print("맛있게 드십시오.")
        break
    except ValueError:
        print("입력이 잘못되었습니다.")
    except ZeroDivisionError:
        print("0으로 나눌수 없습니다.")