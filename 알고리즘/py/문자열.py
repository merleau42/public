#문자열 정렬
''.join(sorted("yaswa")) == "YASWA"


#리스트로 변환
list('문자열') == ['문', '자', '열']
list(map(콜백,'이터러블')) == [ F('이'), F('터'), F('러'), F('블') ]


#문자의 갯수
"banana".count("a") == 3


#거꾸로 읽기
[::-1]


#대소문자 변환
"abcde".upper() == "ABCDE"
"ABCDE".lower() == "abcde"
"AbCdE".swapcase() == "aBcDe"


#첫 글자만 대문자로 
"aWasD".capitalize()


#아스키
chr(32)  ==  ' '
chr(65)  ==  'A'
chr(92)  ==  'a'

ord(' ') ==  32
ord('A') ==  65
ord('a') ==  92


# 인덱스로 순회
for i in range(len('문자열')):
  print (x[i])


# 지정 문자 3개만 바꾸기
'e;x;a;m;p;l;e'.replace(";", 3) == 'exam;p;l;e'


# max, min 은 문자열도 크기 비교 가능
max('123','456') == '456'
min('123','456') == '123'