#-*- coding:utf-8 -*-

if True:                                   # import 리스트
  # 모듈 [기초적인 기능] 
  import os
  import codecs
  from time import sleep
  from random import random


  # 모듈 [선별/정리]
  import re                                 # 정규표현식 (regex)
  #import pandas                             # 자료 정돈

  # 모듈 [웹 일반]
  import requests                           # URL 접근 / Raw 데이터 요청
  import urllib                             # html 확장자 접근

  # 클래스 [웹 파싱]
  from bs4            import BeautifulSoup  # html을 이용해서 편식
  from selenium       import webdriver      # 브라우저를 실행해서 편식

  # 클래스 [브라우저 조작]
  from selenium.webdriver.common.keys import Keys
  from selenium.webdriver.chrome.options import Options


if True:
  def 소스보기(URL): # URL(str) ---> return HTML
     try:
        날것 = requests.get(URL)              # URL 에 접근하여 내역을 받아옵니다      
        html = 날것.content                   # 내역의 html 정보를 추출합니다

        날것.close()                          # 사용한 객체는 소멸시켜서 메모리를 관리합니다

        return html
        
     except:
        return ""                           # 문제 발생시 빈 소스를 전달합니다

  def 새폴더(경로): # 폴더가 없으면 새로 만들어지고, 이미 있으면 그냥 넘어갑니다
     try:
         os.mkdir(경로)

     except FileExistsError as e:
         print(e)        

  def 다운(경로, 파일URL): # 파일의 URL에 접근하고, 접근한 파일의 비트를, 로컬 경로에 복제합니다

     객체 = open(경로, 'wb')

     날것 = requests.get(파일URL)
     객체.write (날것.content)

     객체.close
     날것.close

  def 읽기_string(경로):

      with open(경로, 'r', encoding="utf-8") as A:
         return A.read()

  def 읽기_list(경로, 찾아, 바꾸기): # 파일로부터 필사된 결과물을 리스트로 리턴합니다
       
     with open(경로, 'r', encoding="utf-8") as A:               # 객체 A에다가 로컬 파일을 가져옵니다
    
         필사 = []                            # 필사는 처음에는 백지입니다

         for line in A.readlines():           # 객체 A의 내용을 한줄씩 탐색합니다
            line=line.replace(찾아, 바꾸기)
            필사.append(line)                  # 리스트를 한 칸씩 불려나갑니다

         return 필사                 

  def 읽기_set(경로, 찾아, 바꾸기): # 파일로부터 필사된 결과물을 set로 리턴합니다

     with open(경로, 'r', encoding="utf-8") as A:
    
         필사 = set()

         for line in A.readlines():
            line=line.replace(찾아, 바꾸기)
            필사.add(line)                    
         return 필사  

  def 경로내파일명 (경로, regex_이름형식): # 폴더 내에서 조건에 맞는 파일 이름을 리스트로 리턴
   regex_이름형식 = regex_이름형식 + '\0'
   l = os.listdir(경로)
   ll = []

   print (len(l), " 개 파일 발견")
   for i in l:

      if re.match(regex_이름형식, i+'\0'):
         ll.append (i)
   
   print (len(ll), " 개 파일명 리턴")
   return ll

  def 덮어쓰기(경로, 변수):                       # 넘겨받은 내용을 파일 경로에 문자열로 출력합니다 (덮어쓰기)

     with open(경로, 'w', encoding="utf-8") as A:

         if type(변수) == type(list()):
             A.writelines('\n'.join(변수) )

         else:
               A.write ( str(변수) )

  def 이어쓰기(경로, 변수):                       # 넘겨받은 내용을 파일 경로에 문자열로 출력합니다 (기존 내용에 이어붙이기)

     with open(경로, 'a', encoding="utf-8") as A:

         if type(변수) == type(list()):
             A.writelines('\n'.join(변수) )

         else:
             A.write ( str(변수) )

  def 스트레인저(리스트, 스트링):                  # 넘겨받은 리스트를, 스트링에 덧붙여서 돌려줍니다
    return 스트링.join(리스트)

  def 리스트링 (스트링):
    return re.findall (r'.+', 스트링)

  def 셀래(드라이버, sleep_초, url):                      # 드라이버가 URL을 실행하고, 기다렸다가 html을 가져옵니다
     드라이버.get(url)
     sleep(sleep)

     return 드라이버.page_source

  def 크롬(가로, 세로, headless):

      ops = Options()
      ops.add_argument("--window-size="+str(가로)+","+str(세로) )
      if headless:
         ops.add_argument("headless")
         print ("headless 모드로 실행합니다")
      on = webdriver.Chrome("chromedriver", chrome_options=ops)

      return on

  def 아스키 (숫자or문자):                         # 코드를 문자로, 문자를 코드로 리턴. 'keys'는 내용을 나열.
      k = type(숫자or문자)
      keys = """
        32→  	33→ !	34→ "	35→ #	36→ $	37→ %	38→ &	39→ '	40→ (	41→ )
        42→ *	43→ +	44→ ,	45→ -	46→ .	47→ /
        48→ 0	49→ 1	50→ 2	51→ 3	52→ 4	53→ 5	54→ 6	55→ 7	56→ 8	57→ 9
        58→ :	59→ ;	60→ <	61→ =	62→ >	63→ ?	64→ @
        65→ A	66→ B	67→ C	68→ D	69→ E	70→ F	71→ G	72→ H	73→ I	74→ J
        75→ K	76→ L	77→ M	78→ N	79→ O	80→ P	81→ Q	82→ R	83→ S	84→ T
        85→ U	86→ V	87→ W	88→ X	89→ Y	90→ Z
        91→ [	92→ \	93→ ]	94→ ^	95→ _	96→ `
        97→ a	98→ b	99→ c	100→ d	101→ e	102→ f	103→ g	104→ h	105→ i	106→ j
        107→ k	108→ l	109→ m	110→ n	111→ o	112→ p	113→ q	114→ r	115→ s	116→ t
        117→ u	118→ v	119→ w	120→ x	121→ y	122→ z
        123→ {	124→ |	125→ }	126→ ~	"""

      if 숫자or문자=='keys':
        return keys

      if k==type(str()):
        try:
            return ord(숫자or문자)
        except:
            return '문자는 한 글자를 입력해주세요'

      elif k==type(int()):
        return chr(숫자or문자)

#### 환경 ####
입출력 = 'D:\파이썬\파이썬 입출력\\20200601\\'
새폴더 (입출력)

if True:
    구글 = "https://www.google.com/search?&tbm=isch&q="
    얼글 = "https://www.google.com/search?&tbm=isch&tbs=itp:face&q="
    네이버 = "https://search.naver.com/search.naver?where=image&query="

#### 작업 ####

#driver = 크롬(800,10,False)
l = 읽기_list(입출력 + 'undone2.txt', '','')
n=1

for i in l:
    sleep(0.3)
    BS = BeautifulSoup(소스보기(i),"html.parser")
    try:
        z = BS.find("table",{"class":"display"})
        name = z.find("div").get_text()

        zz = z.findAll("tr", {"class":"altrow0"})
        game = zz[0].div.a.get_text()
        extn = zz[2].td.find_next_sibling().get_text()
        numb = re.sub(r'.+?/(\d+)/\s+', r'\1', i)
        이어쓰기 (입출력 + '메타데이터 수집.txt', numb+'\t'+name+'\t'+game+'\n')

        pic = 'https://www.models-resource.com' + BS.find("div",{"class":"bigiconbody"}).img['src']
        print ("now: " + numb, n)
        n=n+1
        다운 (입출력 + '샘플이미지2\\' + re.sub(r'.+/(.+)', r'\1', pic), pic)
    except:
        이어쓰기 (입출력 + '메타데이터 수집 에러2.txt', i)