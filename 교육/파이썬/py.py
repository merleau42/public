for j in range(0,11):
	print(f'[{j}]', end='\t')
print()

for i in range(1,21):
	print(f'[{i}]', end='\t')
	for j in range(1,11):
		print(i%j, end='\t')
	print()