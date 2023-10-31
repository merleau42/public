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
				z=re.findall(r'.+',f.read())

			else:
				z=str()
				for i in f.readlines():
					z+=i

		return z

# list1 = 불러오기('D:\크롤링\솔브닥\풀문제1', list)
# list2 = 불러오기('D:\크롤링\솔브닥\풀문제2', list)
# list3 = 불러오기('D:\크롤링\솔브닥\풀문제3', list)


# editA = {'Sprout':0, 'Bronze':0, 'Silver':5, 'Gold':10, 'Platinum':15}
# editB = {'I':5, 'II':4, 'III':3, 'IV':2, 'V':1, 'X':0}

# for line in list3:
# 	meta = line.split('\t')

# 	meta[1] = editA[ meta[1] ]
# 	meta[2] = editB[ meta[2] ]

# 	newMeta = [ meta[0], str(meta[1] + meta[2]), meta[3], meta[4] ]
	
# 	이어쓰기('D:\크롤링\솔브닥\풀문제4', '\t'.join(newMeta))



list5 = 불러오기('D:\크롤링\솔브닥\풀문제5', list)


for line in list5:
	meta = line.split('\t')

	include = {"#0-1 너비 우선 탐색0_1_bfs": "",
	"#2-sat2_sat": "",
	"#3차원 기하학geometry_3d": "",
	"#Heavy-light 분할hld": "",
	"#KMPkmp": "",
	"#utf-8 입력 처리utf8": "",
	"#가우스 소거법gaussian_elimination": "",
	"#가장 긴 증가하는 부분 수열: O(n log n)lis": "",
	"#값 / 좌표 압축coordinate_compression": "",
	"#강한 연결 요소scc": "",
	"#게임 이론game_theory": "",
	"#경사 하강법gradient_descent": "",
	"#고속 푸리에 변환fft": "",
	"#구성적constructive": "",
	"#구현implementation": "",
	"#그래프 이론graphs": "",
	"#그래프 탐색graph_traversal": "",
	"#그리디 알고리즘greedy": "",
	"#기댓값의 선형성linearity_of_expectation": "",
	"#기하학geometry": "",
	"#깊이 우선 탐색dfs": "",
	"#너비 우선 탐색bfs": "",
	"#누적 합prefix_sum": "",
	"#느리게 갱신되는 세그먼트 트리lazyprop": "",
	"#다각형의 넓이polygon_area": "",
	"#다이나믹 프로그래밍dp": "",
	"#다차원 세그먼트 트리multi_segtree": "",
	"#단절점과 단절선articulation": "",
	"#데이크스트라dijkstra": "",
	"#덱deque": "",
	"#덱을 이용한 다이나믹 프로그래밍dp_deque": "",
	"#두 포인터two_pointer": "",
	"#라빈–카프rabin_karp": "",
	"#런타임 전의 전처리precomputation": "",
	"#뤼카 정리lucas": "",
	"#많은 조건 분기case_work": "",
	"#매개 변수 탐색parametric_search": "",
	"#매내처manacher": "",
	"#머지 소트 트리merge_sort_tree": "",
	"#모듈로 곱셈 역원modular_multiplicative_inverse": "",
	"#뫼비우스 반전 공식mobius_inversion": "",
	"#무작위화randomization": "",
	"#문자열string": "",
	"#물리학physics": "",
	"#미적분학calculus": "",
	"#밀러–라빈 소수 판별법miller_rabin": "",
	"#배낭 문제knapsack": "",
	"#백트래킹backtracking": "",
	"#번사이드 보조정리burnside": "",
	"#벌리캠프–매시berlekamp_massey": "",
	"#베이즈 정리bayes": "",
	"#벨만–포드bellman_ford": "",
	"#보로노이 다이어그램voronoi": "",
	"#보이어–무어 다수결 투표majority_vote": "",
	"#볼록 껍질convex_hull": "",
	"#볼록 껍질을 이용한 최적화cht": "",
	"#볼록 다각형 내부의 점 판정point_in_convex_polygon": "",
	"#분리 집합disjoint_set": "",
	"#분할 정복divide_and_conquer": "",
	"#분할 정복을 이용한 거듭제곱exponentiation_by_squaring": "",
	"#브루트포스 알고리즘bruteforcing": "",
	"#비둘기집 원리pigeonhole_principle": "",
	"#비트 집합bitset": "",
	"#비트마스킹bitmask": "",
	"#비트필드를 이용한 다이나믹 프로그래밍dp_bitfield": "",
	"#사칙연산arithmetic": "",
	"#삼분 탐색ternary_search": "",
	"#생일 문제birthday": "",
	"#선분 교차 판정line_intersection": "",
	"#선인장cactus": "",
	"#선형대수학linear_algebra": "",
	"#세그먼트 트리segtree": "",
	"#센트로이드centroid": "",
	"#소수 판정primality_test": "",
	"#수치해석numerical_analysis": "",
	"#수학math": "",
	"#순열 사이클 분할permutation_cycle_decomposition": "",
	"#스위핑sweeping": "",
	"#스택stack": "",
	"#스프라그–그런디 정리sprague_grundy": "",
	"#슬라이딩 윈도우sliding_window": "",
	"#시뮬레이션simulation": "",
	"#아호-코라식aho_corasick": "",
	"#애드 혹ad_hoc": "",
	"#양방향 탐색bidirectional_search": "",
	"#에라토스테네스의 체sieve": "",
	"#연결 리스트linked_list": "",
	"#오목 다각형 내부의 점 판정point_in_non_convex_polygon": "",
	"#오일러 경로 테크닉euler_tour_technique": "",
	"#오일러 경로eulerian_path": "",
	"#오일러 지표 (χ=V-E+F)euler_characteristic": "",
	"#오일러 피 함수euler_phi": "",
	"#오프라인 쿼리offline_queries": "",
	"#외판원 순회 문제tsp": "",
	"#우선순위 큐priority_queue": "",
	"#위상 정렬topological_sorting": "",
	"#유클리드 호제법euclidean": "",
	"#이분 그래프bipartite_graph": "",
	"#이분 매칭bipartite_matching": "",
	"#이분 탐색binary_search": "",
	"#이중 연결 요소biconnected_component": "",
	"#임의 정밀도 / 큰 수 연산arbitrary_precision": "",
	"#자료 구조data_structures": "",
	"#작은 집합에서 큰 집합으로 합치는 테크닉smaller_to_larger": "",
	"#재귀recursion": "",
	"#접미사 배열과 LCP 배열suffix_array": "",
	"#정규 표현식regex": "",
	"#정렬sorting": "",
	"#정수론number_theory": "",
	"#제곱근 분할법sqrt_decomposition": "",
	"#조합론combinatorics": "",
	"#중간에서 만나기mitm": "",
	"#중국인의 나머지 정리crt": "",
	"#차분 공격differential_cryptanalysis": "",
	"#차수열degree_sequence": "",
	"#최대 유량 최소 컷 정리mfmc": "",
	"#최대 유량flow": "",
	"#최소 공통 조상lca": "",
	"#최소 비용 최대 유량mcmf": "",
	"#최소 스패닝 트리mst": "",
	"#최소 외접원min_enclosing_circle": "",
	"#커넥션 프로파일을 이용한 다이나믹 프로그래밍dp_connection_profile": "",
	"#큐queue": "",
	"#크누스 최적화knuth": "",
	"#통계학statistics": "",
	"#트라이trie": "",
	"#트리 동형 사상tree_isomorphism": "",
	"#트리trees": "",
	"#트리를 사용한 집합과 맵tree_set": "",
	"#트리에서의 다이나믹 프로그래밍dp_tree": "",
	"#파싱parsing": "",
	"#페르마의 소정리flt": "",
	"#평면 그래프planar_graph": "",
	"#포함 배제의 원리inclusion_and_exclusion": "",
	"#폴라드 로pollard_rho": "",
	"#플로이드–워셜floyd_warshall": "",
	"#피타고라스 정리pythagoras": "",
	"#픽의 정리pick": "",
	"#해시를 사용한 집합과 맵hash_set": "",
	"#해싱hashing": "",
	"#홀의 결혼 정리hall": "",
	"#확률론probability": "",
	"#확장 유클리드 호제법extended_euclidean": "",
	"#회전하는 캘리퍼스rotating_calipers": "",
	"#휴리스틱heuristics": "",
	"#희소 배열sparse_table": ""}

	for e in meta[3].split('#'):
		try:
			include[f'#{e}']="1"
		except:
			continue
	
	print (include.values())
	print ('\n')

	checked = [ meta[0], meta[1], meta[2] ]
	checked += list(include.values())
	이어쓰기 ('D:\크롤링\솔브닥\문제 마당2', '\t'.join(checked))

