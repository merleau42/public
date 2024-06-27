import os, gc
import time, random
import re
import clipboard
import requests
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys

if '셀레늄':
	def 구동(url="", headless=False):
		chrome_options = Options()

		if headless:
			chrome_options.add_argument('headless')

		a = webdriver.Chrome('D:\크롤링\__크롬드라이버\chromedriver.exe', options=chrome_options)
		print ('크롬 구동 완료')

		if url!="":
			a.get(url)
			print ('url 이동')
		return a
	
	def 대기(driver, 방법, 값, 최대=5): #리턴되는 wait 객체는 또 하나의 driver 객체와 유사함
		return WebDriverWait(driver, 최대).until (
			EC.presence_of_element_located ( (방법, 값)) #튜플로 주어져야함
		)
	
	def 전체선택(driver):
		ACT = ActionChains(driver)
		ACT.key_down(Keys.CONTROL).send_keys("a").key_up(Keys.CONTROL).perform()
		print('전체선택')
	
	def 복사(driver):
		ACT = ActionChains(driver)
		ACT.key_down(Keys.CONTROL)
		ACT.send_keys("c")
		ACT.key_up(Keys.CONTROL)
		print('컨트롤+C')

if '뷰티플수프':
	def 끓이기(원본):
		if 원본[0:4]=="http":
			return BeautifulSoup(소스(원본), "html.parser")
		else:
			return BeautifulSoup(원본, "html.parser")

if 'requests':
	def 소스(페이지, HDR=''):
		return requests.get(페이지, headers=HDR).text

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

if 'requests 활용법':
	# 1수신 >>> requests.get(__주소__)
	# 2소스 >>> 수신.text
	pass

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

if '셀레늄 조작법':
	# 1구동 >>> DRIVER = 구동()	----	드라이버 객체 리턴
	# 2이동 >>> DRIVER.get(주소)
	# 3갱신 >>> DRIVER.refresh()
	# 4소스 >>> DRIVER.page_source()
	# 5선택 >>> 요소에 접근 DRIVER.find_element("방법", "값")
	#			부분에 접근 DRIVER.find_element().find_element().find_element()...
	#			요소 리스트 DRIVER.find_elements("방법", "값")
	# 6방법 >>> xpath,  css selector,  (...,  link text,  id,  name,  class name,  tag name)
	# 7쟈스 >>> DRIVER.execute_script( "자바스크립트 코드;" )
	# 7막대 >>> DRIVER.execute_script( "window.scrollTo(0, document.body.scrollHeight);" )
	# 8대기 >>> time.sleep(초)					----	정해진 시간 동안 무조건적으로 실행을 중지. 암시적 대기.
	# 8대기 >>> 대기 (드라이버, "방법", "값")
	#			쿼리의 대상이 존재할 때까지 명시적 대기. 리턴값은 드라이버 객체와 유사한 객체.
	# 8클릭 >>> ELEMENT.click()
	# 8문자 >>> ELEMENT.text
	# 8속성 >>> ELEMENT.get_attribute(...)	href, innerHTML 등등
	# 8입력 >>> ELEMENT.send_keys("값")
	# 8비움 >>> ELEMENT.clear()
	pass

헤더 = { 'Accept': 'text/html', 'range': 'Bytes=0-20',
	'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36',
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
BBS = ['forum','notice','forum2','adver','tips','novel','report','sos','qna','free']
BBS2 = ['ego', 'wisdom']
BBS3 = ['screenshot']

for bbs in BBS3[0:1]:
	for line in 불러오기(f'D:/크롤링/마탐즈/listpage/{bbs}_lines.txt', list):
		meta = line.split('\t')
		index = meta[0]

		url = f'https://www.mabinogi.pe.kr/bbs/view.php?id={bbs}&no={index}'

		r = requests.get(url, headers=헤더)
		time.sleep(0.7)

		덮어쓰기(f'D:/크롤링/마탐즈/content/{bbs}/id={bbs}&no={index}.html', r.text)
		이어쓰기(f'D:/크롤링/마탐즈/log', f'{len(r.text)}, {bbs}, {index}')
		print( len(r.text), f'D:/크롤링/마탐즈/content/{bbs}/id={bbs}&no={index}.html' )