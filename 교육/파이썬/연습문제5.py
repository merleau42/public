n = 9


#------------ 연습문제 5-1
for i in range(1, n+1):
	for j in range(1, n+1):
		if (i >= j):
			print('*', end='')
		else:
			print(' ', end='')
	print()
print('\n')


#------------ 연습문제 5-2
for i in range(1, n+1):
	for j in range(1, n+1):
		if (j > n - i):
			print('*', end='')
		else:
			print(' ', end='')
	print()
print('\n')


#------------ 연습문제 5-3
for i in range(1, n+1):
	for j in range(1, n+1):
		if (i >= j and j > n - i or i <= j and j <= n - i + 1):
			print('*', end='')
		else:
			print(' ', end='')
	print()
print('\n')


#------------ 연습문제 5-4
for i in range(1, n+1):
	for j in range(1, n+1):
		if (i+j >= 2 + n // 2 and \
			i+j <= 1 + n + n //2 and \
			i <= j + n // 2 and \
			i >= j - n // 2):
			print('*', end='')
		else:
			print(' ', end='')
	print()
print('\n')
