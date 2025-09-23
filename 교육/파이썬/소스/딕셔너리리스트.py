movie_list=[
    {'제목':'아바타','평점':9.4},
    {'제목':'반지의제왕','평점':9.4},
    {'제목':'해리포터','평점':8.8},
]
print(movie_list)
for movie in movie_list:
    print(movie, end=' ') #딕셔너리 전체
#리스트의 원소인 딕셔너리 하나씩
print("")
for movie in movie_list: #딕셔너리 하나씩
    for i in movie:#딕셔너리의 키들 가져옴
        print(i, end=' ') #딕셔너리 키 전체 출력