import os
import requests


from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys


def 구동(headless=False, url=""):
  chrome_options = Options()

  if headless: chrome_options.add_argument('headless')

  a = webdriver.Chrome('D://chromedriver', options=chrome_options)
  print ('크롬 구동 완료')

  if url!="":
    a.get(url)
    print ('url 이동')
  return a

def 대기(driver, 방법, 값, 최대=5):
  return WebDriverWait(driver, 최대).until (
    EC.presence_of_element_located ( (방법, 값)) #튜플로 주어져야함
  ) 

  #리턴되는 wait 객체는 또 하나의 driver 객체와 유사함

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