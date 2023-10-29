import os, re, time, random, gc
from myIO import *
import clipboard

import requests, 수프
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

if '뷰티플수프':
  def 잡탕(원본):
    if 원본[0:4]=="http":
        return BeautifulSoup(소스(원본), "html.parser")
    else:
        return BeautifulSoup(원본, "html.parser")

if 'requests':
  def 소스(페이지, HDR=''):
    return requests.get(페이지, headers=HDR).text


헤더 ={
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

