import requests, time, re, os
from collections import defaultdict

if '입출력 모듈':
	def 이어쓰기(파일명, 쓸내용, 타입=str):
		with open(파일명, 'at', encoding='utf8') as f:
			if 타입==str:
				f.write(f'{쓸내용}\n')
			else:
				for i in 쓸내용:
					f.write(f'{i}\n')


	def 덮어쓰기(파일명, 쓸내용, 타입=str):
		with open(파일명, 'wt', encoding='utf8') as f:
			if 타입==str:
				f.write(f'{쓸내용}\n')
			else:
				for i in 쓸내용:
					f.write(f'{i}\n')


	def 불러오기(파일명, by=str):
		with open(파일명, 'r', encoding='utf8') as f:
			if by==list:
				z=re.findall(r'.+',f.read())

			else:
				z=str()
				for i in f.readlines():
					z+=i

		return z



헤더 = { 'Accept': 'text/html', 'range': 'Bytes=0-20',
	'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36',
	'Accept-Encoding':'gzip, deflate, br',
	'Accept-Language':'ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7',
	'Connection':'keep-alive',
	'Sec-Fetch-Dest':'document',
	'Sec-Fetch-Mode':'navigate',
	'Sec-Fetch-Site':'none',
	'Sec-Fetch-User':'?1',
	'Upgrade-Insecure-Requests':'1',
}

#코드 작성
def require():
	try:
		r = requests.get(url, headers=헤더)
		time.sleep(0.6)

		덮어쓰기(f'D:/크롤링/마탐즈/double/{bbs}/id={bbs}&no={index}&page={pg}.html', r.text)
		이어쓰기(f'D:/크롤링/마탐즈/log3_comment', f'id={bbs}&no={index}&page={pg}.html')
		print ( f'id={bbs}&no={index}&page={pg}.html' )
	except:
		이어쓰기(f'D:/크롤링/마탐즈/log3_comment', "예외 발생 10초 대기")
		time.sleep(10)
		require()


for (root, directories, files) in os.walk('D:/크롤링/마탐즈/double/free'):
	print('\n'.join(files))

# d = defaultdict(int)

# for line in 불러오기(f'D:/크롤링/마탐즈/listpage/댓글 51 이상.txt', list):
# 	meta = line.split('\t')
# 	bbs = meta[0]
# 	index = meta[1]
# 	reply = meta[6]

# 	for pg in list(range(2, 2+(int(reply)-1)//50)):
# 		d[bbs] += 1
# 		url = f'https://www.mabinogi.pe.kr/bbs/view_comment.php?id={bbs}&no={index}&page={pg}'
	
# 		require()

# print (d)
#1번부터 10000번 게시물까지 리스트에 담기지 못했음