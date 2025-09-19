import random
#------------ 연습문제 7-2
print("복권 추첨:")
자동 = [ [1, 2, 3], [4, 5, 6] ]

for i in 자동:
	for j in range(0, 3):
		i[j] = random.randrange(1,47)

for i in 자동:
	for j in range(0, 3):
		print(i[j], end=' ')
print()
print()


#------------ 연습문제 7-1, 7-3
학생수 = int(input("학생수 입력: "))
과목수 = int(input("과목수 입력: "))

성적 = list(range(학생수))
for i in range(학생수):
	성적[i] = list(range(과목수))

for i in range(학생수):
	print(f'<학생{i+1}>')
	for j in range(과목수):
		성적[i][j] = int(input(f"   ㄴ{j+1}번째 과목 성적은? "))

print('<성적>')
print('학생', end='\t')
for i in range(과목수):
	print(f'과목{i+1}', end='\t')
print(f'총점\t평균')

for i in range(학생수):
	print(f'학생{i+1}', end='\t')
	for j in range(과목수):
		print(성적[i][j], end='\t')
	print(sum(성적[i]), end='\t')
	print(round(sum(성적[i]) / 과목수,1), end='\n')
