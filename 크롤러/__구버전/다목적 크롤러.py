if True:                                   # import 리스트
  # 모듈 [기초적인 기능] 
  import os
  from time import sleep

  # 모듈 [선별/정리]
  import re                                 # 정규표현식 (regex)
  import pandas                             # 자료 정돈

  # 모듈 [웹 일반]
  import requests                           # URL 접근 / Raw 데이터 요청

  # 클래스 [웹 파싱]
  from bs4            import BeautifulSoup  # html을 이용해서 편식
  from selenium       import webdriver      # 브라우저를 실행해서 편식

  from selenium.webdriver.common.keys import Keys


if True:                                    # 응용 함수 리스트
  def 소스보기(URL):                           # 입력받은 URL 의 html 코드를 전달합니다
     try:
        날것 = requests.get(URL)              # URL 에 접근하여 내역을 받아옵니다      
        html = 날것.content                   # 내역의 html 정보를 추출합니다

        날것.close()                          # 사용한 객체는 소멸시켜서 메모리를 관리합니다

        return html
        
     except:
        return ""                           # 문제 발생시 빈 소스를 전달합니다

  def 뽀글(url):                              # 뷰티플 수프 (=잡탕) 를 끓입니다
  
     return BeautifulSoup( 소스보기(url), "html.parser")
        # 수프 객체가 쑤여졌어요
        # html 소스를 재료로 수프를 쑤고, 좋아하는 건더기만 건져내서 먹어요
    
        # 수프를 담을 그릇이 없다면 바닥에 버려져요.           그릇 = 뽀글(url)
        # return을 담을 동급의 객체가 없다면 바닥에 버려져요.   객체 = 생성(인수)
    
        # L-Value = R-Value ..... 대입 연산자(=)를 이용해서,
        # (지시할 수 없고 휘발적인) R-Value를
        # (지시할 수 있고 영속적인) L-Value로 붙잡아줘요
    
     주의 = "리턴 이후로 작성된 코드는 함수를 빠져나왔기 때문에 아무런 소용이 없어요"

  def 뽀구글(검색어):                            # 구글 이미지 검색 페이지의 html로 수프를 쑵니다

     url = "https://www.google.com/search?&tbm=isch&tbs=itp:face&q=" + 검색어
  
        # 주소창에 다음을 입력해보세요
        #     https://www.google.com/search?&tbm=isch&q=pikachu
        #     https://www.google.com/search?&tbm=isch&tbs=itp:face&q=ashe
  
     return 뽀글(url) 

  def 네이보글(검색어):                           # 네이버 이미지 검색 페이지의 html로 수프를 쑵니다

     url = "https://search.naver.com/search.naver?where=image&query=" + 검색어
  
        # 주소창에 다음을 입력해보세요
        #     https://search.naver.com/search.naver?where=image&query=meganium
        #     
  
     return 뽀글(url)

  def 새폴더(경로):                             # 폴더가 없으면 새로 만들어지고, 이미 있으면 그냥 넘어갑니다
     try:
         os.mkdir(경로)

     except FileExistsError as e:
         print(e)        

  def 다운(경로, 파일URL):                       # 파일의 URL에 접근하고, 접근한 파일의 비트를, 로컬 경로에 복제합니다

     객체 = open(경로, 'wb')
     # 파일을 대변하는 객체를 메모리에 생성합니다.
     # 경로는 "\하위폴더\하위폴더\파일명.확장자" 라는 형식인 풀네임을 기입합니다 (따옴표)

     날것 = requests.get(파일URL)
     # 파일 URL 에 접근하여 내역을 받아옵니다    


     객체.write (날것.content)
     # 넘겨받았던 로컬 경로에, 객체가 내역을 씁니다 ("wb")
    
     # URL이 지목하는 파일과 동일한 비트를 필사하므로,
     # 결국 그 비트가 지닐 수 있는 성질이 그대로 옮겨집니다
    
     # 그림 파일을 이루는 내역도 사실은 0110100011... 의 나열이므로
     # 그림 파일로 확장자를 설정해주는 순간, 똑같은 비트도 그 확장자로서 작동합니다
    
     # 확장자는, 똑같이 그대로있는 비트를, 하필이면 무슨 양식으로서 인식하고 실행할 것인가를 결정합니다


     객체.close # 사용한 객체는 소멸시켜서 메모리를 관리합니다 
     날것.close # 이것이 불편하면 다음을 읽어보세요

  def 읽기(경로):                              # 파일로부터 필사된 결과물을 리스트로 리턴합니다
    
     # [with 생성 as A] 문법에 대해서:
    
     # 함수[값] open(경로, 'r') 로써[로서] 생성되는 객체를,
     # A라는 호환되는 객체로 받아서 활용하겠다는 뜻 입니다

     # 그렇다면 [ A = open(경로,'w') ] 라고 쓸 수도 있지만
     # 그럼에도 [with  생성  as  A   ] 라고 쓰는 이유는
    
     # 객체를 다 사용하고나면 소멸( A.close )시켜야하는데 후자는 파이썬이 알아서 해줍니다

    
     with open(경로, 'r') as A:               # 객체 A에다가 로컬 파일을 가져옵니다
    
         필사 = []                            # 필사는 처음에는 백지입니다

         for line in A:                     # 객체 A의 내용을 한줄씩 탐색합니다
             필사.append(line)                # 리스트를 한 칸씩 불려나갑니다

         return 필사                 

  def 덮어쓰기(경로, 변수):                       # 넘겨받은 내용을 파일 경로에 문자열로 출력합니다 (덮어쓰기)

     with open(경로, 'w') as A:

         if type(변수) == type(list()):
             A.writelines('\n'.join(변수))

         else:
             A.write ( str(변수) )   

  def 이어쓰기(경로, 변수):                       # 넘겨받은 내용을 파일 경로에 문자열로 출력합니다 (기존 내용에 이어붙이기)

     with open(경로, 'a') as A:

         if type(변수) == type(list()):
             A.writelines('\n'.join(변수))

         else:
             A.write ( str(변수) )

  def 리스트링(리스트, 앞선스트링):                  # 넘겨받은 리스트를, 기존 스트링에 덧붙여서 돌려줍니다
    
     # 따옴표를 통해 "즉석으로 작성한 문자열" 도 객체(단, R-Value)이기 때문에 변수는 필요하지 않아요
     return 앞선스트링.join(리스트)

  def 셀래(드라이버,초, url):                      # 드라이버가 URL을 실행하고, 기다렸다가 html을 가져옵니다
     드라이버.get(url)
     sleep(초)

     return driver.page_source

함수요약 = """ 
   

   소스보기                  URL ---> html              (리턴)
   
   뽀글                    URL ---> html ---> 수프      (리턴)
   뽀구글         검색어 ---> URL ---> html ---> 수프      (리턴)
   네이보글        검색어 ---> URL ---> html ---> 수프      (리턴)

   새폴더                     폴더가 없으면 만들어 줌    
   다운                    URL ---> 비트 ---> 파일
    
   읽기                  파일 ---> by객체 ---> 리스트       (리턴)
   덮어쓰기              변수,값 ---> by객체 ---> 파일
   이어쓰기              변수,값 ---> by객체 ---> 파일.
  

   """


#### 작업실 ####
driver = webdriver.Chrome("C://chromedriver")