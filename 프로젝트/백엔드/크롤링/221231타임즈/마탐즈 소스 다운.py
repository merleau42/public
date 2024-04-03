import requests, time, re

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

헤더 = { 'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36',
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
#"C:/Program Files/Python39/python.exe" "d:/크롤링/마탐즈/마탐즈 댓글.py" 
# def 다운():
# 	global errCount
# 	print (url)
# 	try:
# 		URL = f'https://{url.replace("$$","/")}'
# 		r = requests.get(URL, headers=헤더)
# 		time.sleep(0.05)
		
# 		with open( f'D:\크롤링\마탐즈\src\{url}', 'wb') as f:
# 			f.write(r.content)
		
# 		이어쓰기(f'D:\크롤링\마탐즈\log_src', f'{index}, {URL}')
# 		errCount = 0

# 	except:
# 		errCount += 1
# 		if errCount < 3:
# 			이어쓰기(f'D:\크롤링\마탐즈\log_src', "예외 발생 5초 대기")
# 			print ("예외 발생 5초 대기")
# 			time.sleep(5)
# 			다운()

errCount = 0
# for line in 불러오기('D:\크롤링\마탐즈\parsed\edited\src_list_ED', list):
# 	meta = line.split('\t')
# 	index = meta[0]
# 	url = meta[1]

# 	if int(index) <= 36971:
# 		continue

# 	다운()

def 다운():
	global errCount
	print (url)
	try:
		r = requests.get('https://www.mabinogi.pe.kr/bbs/'+url, headers=헤더)
		time.sleep(0.03)
		
		with open( f'D:\크롤링\마탐즈\php\{url}', 'wb') as f:
			f.write(r.content)
		
		이어쓰기(f'D:\크롤링\마탐즈\log_src', url)
		errCount = 0

	except:
		errCount += 1
		if errCount < 3:
			이어쓰기(f'D:\크롤링\마탐즈\log_src', "예외 발생 5초 대기")
			print ("예외 발생 5초 대기")
			time.sleep(5)
			다운()

errCount = 0
for line in 불러오기('D:\크롤링\마탐즈\parsed\edited\zzz', list):
	meta = line.split('\t')
	url = meta[0]

	다운()