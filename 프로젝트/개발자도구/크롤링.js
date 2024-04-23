"디시 크롤링 ㅡ 로컬 스토리지 활용"
try {if(n==1) {Q=x=>document.querySelector(x)??E; Qs=x=>document.querySelectorAll(x)??E; S=window.localStorage;} //N을 타이머, 틱으로 활용.
if(n==2) {go = (x,y)=>document.location.href = `https://gall.dcinside.com/mgallery/board/view/?id=${x}&no=${y}` } //페이지 이동 함수
if(n==3) { //정상 페이지 여부 확인, 이상이 없다면 페이지 URL을 참고하여 위치 정보를 스토리지에 갱신, 이상이 있다면 스토리지 값을 꺼내와서 직접 갱신
if (now=document.URL.match(/.+?id=(.+?)&no=(\d+)/)) {S.setItem('현갤',now[1]); S.setItem('글번',now[2]);}
else {S.setItem('글번',S.getItem('글번')*1-1); go(S.getItem('현갤'),S.getItem('글번'))} //이상 URL은 위치 정보 없음, 스토리지 써서 일찍 이동
}if(n==4) {D.구분선 = "ㅩ";   D.날짜=Q('span.gall_date').innerText;   D.갤명=now[1];   D.번호=now[2];   D.제목=Q('h3.title').innerText;
D.쓰니=Array.from(Qs('div>.nickname, div>.ip')).map(x=>x.innerText).join('');  D.본문=Q('div.write_div').innerText.replace(/\n+/g,'　');
D.댓글=('\n'+Q('ul.cmt_list').innerText.replace(/\n\n(.+?)\n\n/g,'\n"$1" ').replace(/\n삭제/g,'')).replace(/\n(.+?)\n/g,'【$1】');
/*D.그림 = Array.from(Qs('img[onerror]')).map(x=>x['src']).join(', ');*/}
if(n==5) S.setItem(D.갤명+' '+D.번호, Object.values(D).join('\t')) //이상 페이지는 머물지않고 바로 이동했으므로, 정상 페이지만 보관됨
if(n==10) go(now[1], now[2]*1-1+''); //정상 페이지라면 10틱을 기다려서 비로소 이동함. 차단을 방지하기 위해서 타이머 조절 필요.
n++; D;} catch {n=1; D=new Object; E=document.createElement("EMPTY"); } //참조 오류를 일으켜서 처음 한 번만 변수 선언


"디시 크롤링 ㅡ 로컬 스토리지 복사"
copy(Array.from(Object.values(localStorage)).sort().map(x=>x.replace(/\n/g,'')).join('\t').replace(/ㅩ\t/g,'\n'));