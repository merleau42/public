"사이에듀1"
try{if(true){ // 변수는 페이지마다 휘발적. not defined 발생 예정: catch 문에서 다시 선언됨 // true 앞에 느낌표를 붙여서 실행 중지.
    if (e=문서.LectureContentiFrame.myAudio) {e.volume=0.03};
	if (e=문서.LectureContentiFrame.myVideo) {e.volume=0.03};
    if (zero<1) window.close();  // 현재 시간이 00:00에서 흐르지 않음. 마지막을 지나고, 접근을 삼가야하는 페이지에 도달함: 강제 종료대기
    if (done<1) top.fnMove(Number(top.SN_ID.value)+1);  // 밟고 넘어가야 후환이 없는 미지의 로직이 수행되었기를 기다리면서: 넘어감
    if      (top.view_sec_sum.textContent == '학습완료') done -= 1;
    else if (top.view_sec_sum.textContent == '00:00') zero -= 1;
    else    {done = 10;  zero = 5;}
      문서.LectureContentiFrame.isCourseName
    + TAB("", 문서.title.match(/.*\](.*)/)[1]).replace(/[.\d]/g,"")
    + TAB("남은시간(초)", top.SEC_STD.value - top.SEC_SUM.value) + TAB("추가대기(틱)", done) + TAB("오류허락(틱)", zero);
}} catch(err) { 문서 = top.document; TAB = (x,y)=>`   ▶   ${x} ${y}`; done = 10; zero = 5; err;}  // 선언



"사이에듀2"
try{if(!true){
	if (e=콘텐츠.myVideo) e.volume=0.01; if (e=콘텐츠.myAudio) e.volume=0.01;  현재=top.view_sec_sum.textContent;
	종료대기 += (현재 == '00:00') - ( Number(top.SEC_STD.value) <= Number(top.SEC_SUM.value) ); 강의명=콘텐츠.isCourseName;
    if (종료대기<1) top.fnMove (Number(top.SN_ID.value)+1);
	if (종료대기>15) {window.location.href = 주소.replace(/\d+&sn_id=\d+/i,`${sid[i]}&sn_id=${mod + snid[i]}`);}
	강의명 + `(${n[1]})` + 탭("", 문서.title.match(/.*\](.*)/)[1]).replace(/[.\d]/g,"")
    + 탭("남은시간(초)", top.SEC_STD.value - top.SEC_SUM.value) + 탭("추가대기(틱)", 종료대기)
}} catch { 문서=top.document; 콘텐츠=문서.LectureContentiFrame;
	콘텐츠=top.document.LectureContentiFrame; 종료대기=7; 탭 = (x,y)=>`　▶　${x} ${y}`;
	주소=document.URL; n=주소.match(/(\d+)&sn_id=(\d+)/i);                                         mod=160;
	snid = [ 1095789,1097423,1098442,1100727,1103614,1111983,1112334,1112638,1095789 ]; 
	sid = [ 5183,5188,5191,5198,5207,5229,5230,5231,5183 ]; i=sid.indexOf(Number(n[1]))+1;}