import requests
from bs4 import BeautifulSoup

헤더 ={
      'accept': 'text/html',
      #'accept': 'text/html#,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
      'Accept-Encoding':'gzip, deflate, br',
      'Accept-Language':'ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7',
      'Sec-Fetch-Dest':'document',
      'Sec-Fetch-Mode':'navigate',
      'Sec-Fetch-Site':'none',
      'Sec-Fetch-User':'?1',
      'Upgrade-Insecure-Requests':'1',
      'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36',
}

def 소스(페이지, HDR=''):
  return requests.get(페이지, headers=HDR).text


def 잡탕(원본):
  if 원본[0:4]=="http":
      return BeautifulSoup(소스(원본), "html.parser")
  else:
      return BeautifulSoup(원본, "html.parser")