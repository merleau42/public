import random

cnt = [0,0,0,0,0,0,0]
for i in range(100000):
	cnt[random.randrange(1,7)] += 1

for i in range(1,7):
	횟수 = str(cnt[i]).rjust(5, ' ')
	비율 = round(cnt[i]/100000 * 100, 1)
	print(f'주사위 {i}번: {횟수}회 등장({비율}%)')
print()


전적=[0,0,0]
while True:
	나 = int(input("1.가위  2.바위  3.보  4.종료 "))
	if 나==4:
		break
	컴 = random.randrange(1,4)
	print(f'당신({[None, "가위", "바위", "보"][나]})', end=' vs ')
	print(f'컴터({[None, "가위", "바위", "보"][컴]})', end=' --> ')

	if 컴 == 11 % (나 + 2):
		전적[2] += 1
		print("패배!")
	elif 나 == 컴:
		전적[1] += 1
		print("무승부!")
	else:
		전적[0] += 1
		print("승리!")
	print(f'[전적]  {전적[0]}승  {전적[1]}무  {전적[2]}패')
	print()
