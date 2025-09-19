try: #예외가 발생할만한 코드를 적는다
    age = int(input("나이를 입력하세요:"))
    print("나이:",age)
except ValueError: #ValueError타입 오류면 여기로
    print("입력이 잘못되었습니다.")