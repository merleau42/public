import os, re, time, random, gc
from myIO import *
import clipboard, 매크로, 모듈

import requests, 수프
from bs4 import BeautifulSoup

if '셀레늄':
  from selenium import webdriver
  from selenium.webdriver.chrome.options import Options
  from selenium.webdriver.support.ui import WebDriverWait
  from selenium.webdriver.common.by import By
  from selenium.webdriver.support import expected_conditions as EC
  from selenium.webdriver.common.action_chains import ActionChains
  from selenium.webdriver.common.keys import Keys
  연습장='연습장'

if '셀레늄 함수':
  def 구동(headless=False, url=""):
    chrome_options = Options()

    if headless: chrome_options.add_argument('headless')

    a = webdriver.Chrome('D://chromedriver', options=chrome_options)
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

if '셀레늄 사용법':
  #  requests 활용법
  # .get (주소)
  # .text

  #  셀레늄 조작법
  # 구동 >>> 구동 () >>> 드라이버 객체 리턴
  # 이동 >>> .get (주소)
  # 선택 >>> .find_element("방법", "값")  id  xpath  link text  name  class name  tag name  css selector
  # 대기 >>> 대기 (드라이버, "방법", "값") >>> 해당 값이 존재할 때까지 명시적 대기. 리턴값 == (유사)드라이버 객체.
  # 클릭 >>> .click()
  # 속성 >>> .get_attribute()
  # 입력 >>> .send_keys("값")
  # 비움 >>> .clear()
  # 소스 >>> .page_source()

  #  수프 활용법
  # 수프 >> 수프.잡탕 (URL 또는 HTML)
  # 찾기 >> .find("태그", class_="")
  # 형제 >> .next_sibling, .previous_sibling
  pass


헤더 ={
      'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
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

접미="(?:ability|able|ableness|ably|age|al|ality|ally|ance|ant|ar|arity|ary|ate|ated|atic|ation|ative|atory|bed|bing|cy|d|ded|den|der|dest|ding|dingly|dish|dly|dness|dom|e|eal|ed|edly|edness|ee|en|ence|ency|ent|eous|er|erly|ern|ery|es|ess|est|ey|ful|fully|fy|ged|ger|ging|gy|hood|ial|ially|ibility|ible|ic|ical|ient|ify|ile|ily|ination|ine|iness|ing|ingly|ingness|ion|ional|ionary|ish|ishness|ism|ist|istic|ition|itive|ity|ive|ively|ize|ked|king|ky|l|lable|led|ler|less|lessly|lessness|lest|lic|like|liness|ling|lke|lly|ly|mable|mation|med|ment|mer|mest|ming|my|n|nability|nable|nce|ncy|ned|ner|ness|ning|ningly|nt|ntal|ny|or|ory|ous|pable|ped|per|ping|pingly|py|r|rable|ral|red|rer|ress|ring|rize|ry|s|sed|ses|ship|shp|sing|sion|sm|some|st|ster|sy|t|tability|table|tably|tal|te|ted|ten|ter|test|th|thy|tible|tic|tically|ting|tingly|tish|ty|ual|ually|ular|ure|y|rence|ities|encies|ian|abilities|ties|ise|ising|itarian|izes|izing|ization|ification|ified|ifies|isation|ese)"
한깎="(?:abilities|ability|able|ableness|ably|action|actory|age|ality|ally|ance|ant|arian|arity|ary|ate|ated|atic|ation|atious|ative|atorial|atory|bed|bing|cal|ces|cial|ded|den|dence|dent|der|dest|ding|dingly|dish|dly|dness|dom|eal|edly|edness|en|ence|encies|ency|ent|eous|erly|ern|ery|ess|est|etic|etical|ful|fully|ged|ger|ging|hood|iability|iable|iableness|iably|iage|ial|ialize|ially|ian|iance|iant|iate|iation|ibility|ible|ibly|icable|ical|icality|ically|icalness|icant|ication|icative|icatory|ice|icit|icity|ied|ient|ier|ies|iest|iety|ification|ified|ifies|iful|ify|ihod|ihood|ile|iless|ily|iment|inal|inate|ination|ine|iness|ing|ingly|ingness|inous|ion|ional|ionary|ior|ious|ise|ish|ishly|ishness|ising|ism|isome|ison|ist|istic|itarian|ite|ities|ition|itive|ity|ive|ively|iveness|ization|ize|izes|izing|ked|king|lable|led|ler|less|lessly|lessness|lest|lic|lid|like|liness|ling|lke|lly|lor|mable|mation|med|ment|mer|mest|ming|nability|nable|nce|ncy|ned|ner|ness|ning|ningly|ntal|or|orial|orily|ory|ous|ously|pable|ped|per|ping|pingly|ption|ptive|rable|ral|red|rence|rer|ress|ring|rize|sed|ses|ship|shp|sile|sing|sion|sive|some|sory|ssible|ssion|ssive|ster|stic|sus|tability|table|tably|tal|tary|ted|ten|ter|test|thy|tible|tic|tically|ties|ting|tingly|tinous|tion|tious|tish|tive|tize|tory|ual|ually|ude|ular|ure|ves|isation)"


def 구성요소(자료형):
  if type(자료형) == "":
    S=set()
    for i in 자료형: S.add(i)
    L=list(S)
    L.sort()
    return ''.join(L)
  


def 해당제거():
  A = myIO.불러오기('2기2차렘마')
  B = myIO.불러오기('거를것',True)

  A = re.sub(r'\s+','\t',A)

  for i in B:
    print(i)

    Q=re.compile("[a-z]*"+i.lower()+"[a-z]*\t")
    A=re.sub(Q,'\t',A)
  
  A = re.sub(r'\s+','\n',A)
  myIO.덮어쓰기('2기3차렘마', A)



def 중복표기(mode):
  A = 불러오기('렘마A1')
  B = 불러오기('렘마A1',True)
  
  for i in B:
    if i[1]=="★": continue
    h = re.match(r'♬(.+?)＠', i).group(1)
    print (h)
    if mode==0: A = re.sub(r"♬("+h+접미+")＠",r"♬★\1＠",A)
    if (mode==1 and len(h)>5): A = re.sub(r"♬("+h[:-1]+한깎+")＠",r"♬★\1＠",A)

  덮어쓰기('렘마A2', A)



def 포함시제거():
  A = 불러오기('2기2차렘마')
  B = 불러오기('거를것',True)

  A = re.sub(r'\s+','\t',A)

  for i in B:
    print(i)

    Q=re.compile("[a-z]*"+i.lower()+"[a-z]*\t")
    A=re.sub(Q,'\t',A)
  
  A = re.sub(r'\s+','\n',A)
  덮어쓰기('2기3차렘마', A)

driver = 구동(True)


def 페이지단어(URL):
    driver.get(URL)
    time.sleep(1)

    S = set()

    for i in driver.find_element(By.XPATH, "//*[@id='container']/div").find_elements(By.TAG_NAME,"a"):
        S.add (  re.sub(r'\d+',"",i.text)  )

    이어쓰기('ㄱㄱㅎㅎ', S, list)
    try:
      S.remove('')
    except:
      pass
    print (S)

    return len(S)



for ㄱㅎ in 불러오기('순회할ㄱㅎ_', list):
  i=1
  while (페이지단어(f"http://www.jaum.kr/index.php?w={ㄱㅎ}&k=dic&page={i}")): i+=1



#if len(S): 다음페이지()
#else 다음페이지()

#페이지단어(f"http://www.jaum.kr/index.php?w={'ㄱㄱ'}&k=dic&page=14")
#페이지단어(f"http://www.jaum.kr/index.php?w={'ㄱㄱ'}&k=dic&page=15")

#def 다음페이지():

def main():
  pass
