import os, gc
import time, random
import re

if '입출력 모듈':
	def 이어쓰기(파일명, 내용, 타입=str):
		with open(파일명, 'at', encoding='utf8') as f:
			if 타입==str:
				f.write(f'{내용}\n')
			else:
				for i in 내용:
					f.write(f'{i}\n')


	def 덮어쓰기(파일명, 내용, 타입=str):
		with open(파일명, 'wt', encoding='utf8') as f:
			if 타입==str:
				f.write(f'{내용}\n')
			else:
				for i in 내용:
					f.write(f'{i}\n')


	def 불러오기(파일명, by=str):
		with open(파일명, 'r', encoding='utf8') as f:
			if by==list:
				return re.findall(r'.+',f.read())

			else:
				return f.read()

text = 불러오기('D:\크롤링\솔브닥\풀문제1')
text = re.sub(r'\d+\t', "\n", text)
text = re.sub(r'#', "\n", text)
text = re.sub(r'\n+', "\n", text)

덮어쓰기('태그명', sorted(list(set(re.findall(r'.+',text)))), list)