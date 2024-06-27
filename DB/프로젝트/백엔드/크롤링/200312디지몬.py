import requests
from bs4 import BeautifulSoup


def BS(url):
  given = requests.get(url)
  html = given.content
  given.close()
  return BeautifulSoup(html, "html.parser")


def GoogleImg(keyword):
  return BS("https://www.google.com/search?tbm=isch&q=" + keyword)


def download(url, filename):
  given = requests.get(url)
  out_file = open('./crawl' + filename, 'wb')
  out_file.write(given.content)
  given.close()


# ----------------------------------------------
urls =[
  "https://wikimon.net/index.php?title=Category:Toei_Images&filefrom=agnimon",
  "https://wikimon.net/index.php?title=Category:Toei_Images&filefrom=Cupimon+back.png",
  "https://wikimon.net/index.php?title=Category:Toei_Images&filefrom=Gomamon+adventure+fes+2016.png",
  "https://wikimon.net/index.php?title=Category:Toei_Images&filefrom=Machgaogamon2.jpg",
  "https://wikimon.net/index.php?title=Category:Toei_Images&filefrom=Patamon+side.png",
  "https://wikimon.net/index.php?title=Category:Toei_Images&filefrom=Skullgreymon.gif"]

ls1 =[]
n=100

for j in urls:
    bs1 = BS(j)
    s = bs1.findAll("a", {'class':'image'})


    for i in s:

      bs2 = BS("https://wikimon.net" + i['href'])

      ss = bs2.find("div", {'class':'fullImageLink'})
      ss = ss.find("a")
      download("https://wikimon.net" + ss['href'],    '/디지몬 토에이/' + str(n) + '.png')
      n+=1

      del bs2

    del bs1
