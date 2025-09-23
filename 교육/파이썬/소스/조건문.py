age = 25

if age>=20:
    print("성인")age = input("나이입력:")
age = int(age)

if age>=20:
    print("성인")age = input("나이입력:")
age = int(age)

if age>=20:
    print("성인")
else:
    print("미성년자")score = input("점수입력:")
score = int(score)

if score >= 90:
    print('A')
elif score >= 80:
    print('B')
elif score >= 70:
    print('C')
elif score >= 60:
    print('D')
else:
    print('F')age = input("나이입력:")
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
