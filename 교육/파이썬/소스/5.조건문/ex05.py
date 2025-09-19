age = input("나이입력:")
age = int(age)

if age>=20:
    print("성인")
    if age>=65:
        print("고령자")
    else:
        print("일반")
else:
    print("미성년자")
    if age>=8:
        print("취학")
    else:
        print("미취학")
