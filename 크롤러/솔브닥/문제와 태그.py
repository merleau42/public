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
	def 구동(headless=False, url=""):
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
	def 잡탕(원본):
		if 원본[0:4]=="http":
			return BeautifulSoup(소스(원본), "html.parser")
		else:
			return BeautifulSoup(원본, "html.parser")

if 'requests':
	def 소스(페이지, HDR=''):
		return requests.get(페이지, headers=HDR).text

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
				z=re.findall(r'.+',f.read())

			else:
				z=str()
				for i in f.readlines():
					z+=i

		return z

헤더 = {
	'accept': 'text/html',
	'Accept-Encoding':'gzip, deflate, br',
	'Accept-Language':'ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7',
	'Connection':'keep-alive',
	'Sec-Fetch-Dest':'document',
	'Sec-Fetch-Mode':'navigate',
	'Sec-Fetch-Site':'none',
	'Sec-Fetch-User':'?1',
	'Upgrade-Insecure-Requests':'1',
	'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36',
}

태그 = [ "two_pointer", "tsp", "trie", "trees", "tree_set", "topological_sorting", "ternary_search", "sweeping", "string", "stack", "sqrt_decomposition", "sprague_grundy", "sparse_table", "sorting", "sliding_window", "simulation", "sieve", "segtree", "scc", "regex", "recursion", "randomization", "queue", "pythagoras", "probability", "priority_queue", "primality_test", "prefix_sum", "precomputation", "polygon_area", "point_in_non_convex_polygon", "point_in_convex_polygon", "pigeonhole_principle", "permutation_cycle_decomposition", "parsing", "parametric_search", "offline_queries", "numerical_analysis", "number_theory", "multi_segtree", "mst", "modular_multiplicative_inverse", "mitm", "math", "manacher", "lucas", "linked_list", "linearity_of_expectation", "linear_algebra", "line_intersection", "lca", "lazyprop", "knapsack", "inclusion_and_exclusion", "implementation", "hashing", "hash_set", "greedy", "graphs", "graph_traversal", "geometry", "game_theory", "flt", "floyd_warshall", "flow", "fft", "extended_euclidean", "exponentiation_by_squaring", "eulerian_path", "euler_phi", "euclidean", "dp_tree", "dp_deque", "dp_bitfield", "dp", "divide_and_conquer", "disjoint_set", "dijkstra", "dfs", "deque", "data_structures", "crt", "coordinate_compression", "convex_hull", "constructive", "combinatorics", "case_work", "calculus", "burnside", "bruteforcing", "bitset", "bitmask", "bipartite_matching", "bipartite_graph", "binary_search", "biconnected_component", "bfs", "berlekamp_massey", "bellman_ford", "backtracking", "articulation", "arithmetic", "arbitrary_precision", "ad_hoc", "euler_characteristic", "lis", "suffix_array", "kmp", "3geometry_3d", "2-sat2_sat", "0_1_bfs" ]

if 'requests 활용법':
	# 1수신 >>> requests.get(__주소__)
	# 2소스 >>> 수신.text
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

if '수프 활용법':
	# 1구축 >>> 수프 = 잡탕(URL/HTML)
	# 2소스 >>> print(수프)
	#			print( 수프.prettify() )
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
	# 5속성 >>> 수프(.TAG).TAG["href"]			----	대상이 없으면 에러
	#			수프(.TAG).TAG.get("href")		----	대상이 없으면 None
	# 5문자 >>> 수프(.TAG).TAG.text
	# ㅓㅍ6수정 >>> 수프.TAG				= "태그명 변경"
	#			수프.find(~)			= "태그명 변경"	---- 그런가?
	#			수프.TAG["속성명"]		= "속성값 수정"
	pass

driver = 구동()


for tag in 태그:
	page=0
	while (1):
		page+=1
		driver.get(f"https://solved.ac/search?query={tag}")
		time.sleep(3)
		driver.refresh()
		time.sleep(1)

		escape = driver.find_element("xpath", '//*[@id="__next"]/div/div[2]/div[2]/div[2]').text
		if escape == "해당하는 문제가 없습니다.":
			break

		driver.execute_script("[...document.querySelectorAll('.css-gv0s7n')].forEach(x=>x.click());")
		time.sleep(2)

		driver.execute_script("a=[...document.querySelectorAll('img.css-1vnxcg0 + span')].map(x=>x.innerText);")
		driver.execute_script("b=[...document.querySelectorAll('.css-1m19b4j')].map(x=>x.innerText);")

		이어쓰기('풀문제', driver.execute_script("return a.map((x,i)=>a[i]+'\t'+b[i]);"), list)