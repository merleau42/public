try:
    age = int(input("나이를 입력하세요:"))
    print("나이:",age)
except ValueError:
    print("입력이 잘못되었습니다.")