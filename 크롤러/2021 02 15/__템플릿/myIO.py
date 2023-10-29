import re

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