while True:
    try: #예외가 발생할만한 코드를 적는다
        age = int(input("나이를 입력하세요:"))
        print("나이:",age)
        break
    except ValueError: #ValueError타입 오류면 여기로
        print("입력이 잘못되었습니다.")

# 정수로 변환안되는 문자열 넣으면 ("스물", "스물하나")
# 계속 입력이 잘못되었습니다.
# "20"을 입력하면 변환되고 나이출력하고 break로 종료