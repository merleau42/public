// 시작 주소 ㅡ https://solved.ac/search?query=*1..&sort=level&direction=asc&page=1
try {if (n==15) [...Q('.css-uqcujy, [src*="warn.svg"]')].forEach(x=>x.remove())
else if (n==30) [...Q('button')].slice(1).forEach(x=>x.click())
else if (n==45) [...Q('.css-1pecrf1')].forEach(x=>x.innerText = '@' + x.innerText)
else if (n==60) [...Q('img[src*=tier]')].forEach(x=>x.outerHTML=x.src.match(/^.+\/(.+?)\.svg$/)[1]+'ㅩ')
else if (n==75) W=[...Q('tr')].slice(1).map(tr=>[...Q('td',tr)].map(x=>x.innerText.replace(/\n\s*/,'ㅩ').split('ㅩ')).flat())
else if (n==90) W.forEach(x=>localStorage[x[1]]=x.join('ㅩ'))
// else if (n==99) document.location.href = url.match(/(.+?)(\d+)$/)[1]+(url.match(/(.+?)(\d+)$/)[2]*1+1)
n++;} catch {n=1; function Q(x, y=document) {return y.querySelectorAll(x)}; url = document.URL}

// 로컬 스토리지 불러오기
copy( Object.values(localStorage).join('\n') )