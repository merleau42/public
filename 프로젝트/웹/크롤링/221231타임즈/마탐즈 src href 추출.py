import time, random, os
import re
from bs4 import BeautifulSoup

if '뷰티플수프':
	def 끓이기(원본):
		return BeautifulSoup(원본, "html.parser")

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

if 'Syntactic Sugar':
	# JS에서, ??문법으로 None 대신에 더미 DOM을 리턴하는 것처럼, 파썬도 더미 객체를 리턴하도록 함
	def okay(x):
		더미 = 끓이기('<none>none</none>')
		더미["class"] = ["none"]
		if x == None: return 더미
		else: return x

	# 보통 map함수는 list형으로 감싸는데 편의성과 가독성이 떨어지므로 숏컷을 정의함
	def MAP(fx, x):
		return list(map(fx, x))

if '수프 활용법':
	# 1구축 >>> 수프 = 끓이기(URL/HTML)
	# 2소스 >>> print(수프)
	#			print( 수프.prettify() )		----	prettify로 저장은 신중하게
	# 3태그 >>> 수프.TAG명											----	트리와 속성을 갖는 TAG 객체를 얻음
	#			수프.TAG명.TAG명									----	TAG 객체는, 전체 수프의_ 부분 수프
	#			수프(.html.head).title...							----	부분 수프의_ 부분 수프의_ 부분 수프
	#			수프.title											----	부분 수프를_ 바로 접근
	#			수프.html.body.div.span...							----	find/select 통해서도 얻을 수 있음
	# 3파썬 >>> 수프(.TAG).find(			 "태그명"			)	----	태그
	#			수프(.TAG).find(			 속성=true			)	----	속성
	#			수프(.TAG).find(			 속성="값"			)	----	속성 && 값
	#			수프(.TAG).find(	"태그명",	속성="값"		)	----	태그 && 속성 && 값
	#			수프(.TAG).find(	"태그명",	"클래스명"		)	----	태그 && 클래스
	#			수프(.TAG).find(		class_="클래스명"		)	----	속성처럼 찾을 때는 언더바_ 필요
	#			수프(.TAG).find(	 re.complle("정규식")		)	----	태그명/속성값/클래스명 정규식 지원
	#			수프(.TAG).find_all( 조건 )						----	해당되는 모든 TAG 객체를 리스트로 얻음
	#			수프(.TAG).find_all( 조건, limit=5 )			----	위에서부터 N개만 찾음. find()는 limit=1
	#			수프(.TAG).find_all( 조건, recursive=False )	----	직계차일드만(depth==1) 탐색
	#			수프(.TAG)( 조건 )								----	find_all 함수명 생략하고 괄호만 열어도 됨
	# 3쟈스 >>> 수프(.TAG).select(	'#QuerySelectorAll'	)
	#			수프(.TAG).select_one(	'#QuerySelector'	)
	# 4형제 >>> 수프(.TAG).TAG.next_sibling
	#			수프(.TAG).TAG.previous_sibling
	# 4자손 >>> 수프(.TAG).TAG.contents
	# 5속성 >>> 수프(.TAG).TAG.attrs			----	모든 {속성:값} 일람
	# 5속성 >>> 수프(.TAG).TAG["href"]			----	속성이 없으면 에러
	#			수프(.TAG).TAG.get("href")		----	속성이 없으면 None
	# 5문자 >>> 수프(.TAG).TAG.text
	# 6수정 >>> 수프.TAG				= "태그명 변경"
	#			수프.find(~)			= "태그명 변경"	---- 그런가?
	#			수프.TAG["속성명"]		= "속성값 수정"
	pass

#코드 작성
#"C:/Program Files/Python39/python.exe" "d:/크롤링/마탐즈/마탐즈 src href 추출.py" 

BBS = ['ego','wisdom','forum','notice','forum2','adver','tips','novel','report','sos','qna','free']
BBS2 = ['screenshot']

# for bbs in BBS:
# 	here = f'D:/크롤링/마탐즈/content/{bbs}'
# 	for (root, directories, files) in os.walk(here):
# 		for 파일명 in files:
# 			수프 = 끓이기(불러오기(f'{here}/{파일명}'))
			
# 			href = MAP(lambda x: x.get("href"), 수프.select('[href]'))
# 			src = MAP(lambda x: x.get("src"), 수프.select('[src]'))

# 			이어쓰기(f'D:\크롤링\마탐즈\parsed\parsed_{bbs}.txt', '\n'.join(set(href + src)))
# 			del 수프
# 			del href
# 			del src
			
# 			print (파일명)

# for bbs in BBS2[0:1]:
# 	text = 불러오기(f'D:\크롤링\마탐즈\parsed\parsed_{bbs}.txt', list)
# 	edit = sorted( list(set(text)) )

# 	덮어쓰기(f'D:\크롤링\마탐즈\parsed\edited_{bbs}.txt', '\n'.join(edit))
# 	del text
# 	del edit


#"C:/Program Files/Python39/python.exe" "d:/크롤링/마탐즈/마탐즈 src href 추출.py" 
BBS = ['ego','wisdom','forum','notice','forum2','adver','tips','novel','report','sos','qna','free','screenshot']

for bbs in BBS:
	here = f'D:/크롤링/마탐즈/content/{bbs}'
	for (root, directories, files) in os.walk(here):
		for 파일명 in files:
			수프 = 끓이기(불러오기(f'{here}/{파일명}'))
			
			후보 = MAP(lambda x:x.text, 수프.select('span[onmousedown]'))
			print (후보)

			for name in 후보:
				if '작지만' in name:
					이어쓰기(f'D:\크롤링\마탐즈\작지만', 파일명)