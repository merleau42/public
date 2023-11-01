import os, re, myIO, time, random

import requests, 수프, 셀레늄
from bs4 import BeautifulSoup
from selenium import webdriver


#  requests 활용법
# .get (주소)
# .text

#  셀레늄 조작법
# 구동 >>> 셀레늄.구동 () >>> 셀레늄 객체 리턴
# 이동 >>> .get (주소)
# 선택 >>> find_element("방법", "값")
# 클릭 >>> .click()
# 입력 >>> .send_keys("값")
# 비움 >>> .clear()

#  수프 활용법
# 수프 >> 수프.잡탕 (URL 또는 HTML)
# 찾기 >> .find("태그", class_="")

driver = 셀레늄.구동()

def getByNumProcess(pm):
  driver.get(f'http://pokemongo.inven.co.kr/dataninfo/pokemon/detail.php?code={pm}')
  a=driver.find_element("xpath", '//*[@id="articleView"]/div[1]/h1').text

  이름=re.sub(r'\d+?\.(.+)',r'\1',a)
  공격=driver.find_element("xpath", '//*[@id="articleView"]/div[1]/div[2]/ul/li[8]').text
  방어=driver.find_element("xpath", '//*[@id="articleView"]/div[1]/div[2]/ul/li[10]').text
  체력=driver.find_element("xpath", '//*[@id="articleView"]/div[1]/div[2]/ul/li[12]').text
  속성=driver.find_element("xpath", '//*[@id="articleView"]/div[1]/div[2]/ul/li[2]').text
  상성=driver.find_element("xpath", '//*[@id="articleView"]/div[1]/div[3]/div[2]/table/thead').text + " "

  속성=re.sub(r'[ "]',r'',속성)
  속성=re.sub(r'([a-z])([A-Z])',r'\1 \2',속성)

  print (상성)

  상성=re.sub(r'-','1',상성)
  상성=re.sub(r'[A-z\\]','',상성)
  상성=re.sub(r'\s+',' ',상성)

  약점=re.sub(r' 0\.[0-9]+| 1$',' 0',상성)

  return (pm, 이름, 공격, 방어, 체력, 속성, 상성, 약점)

def getByNum(pm):
  try: return getByNumProcess(pm)
  except:
    X=(pm,0,0,0,0,0,0,0)
    for i in range(1,10):
      try   :  print( getByNumProcess (i*10000+pm)[:] )
      except:  break
    return X

def getByName(pm):
  for i in IO.불러오기('_포켓몬고 영한', True):
    if (pm in i):
      pass

def getPM(pm):
  if   type(pm)==type(1) : return getByNum(pm)
  elif type(pm)==type(''): print('이름으로 찾기')


def main():
  pm=6
  A=getPM(pm)
  print (A[5], A[6], A[7])