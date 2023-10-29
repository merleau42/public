import myIO, re

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