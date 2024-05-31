cadet = ["ahrelee","bohchoi","bonikoo","chan-ypa","changhyu","changwpa","chjeong","chunpark","dae-lee","daeekim","djang","dohukim","dohyeki2","dohyuki2","doji","dojkoo","dongcho","donghwi2","donjeong","donjung","donkim3","doyoukim","dukim","eonoh","esong","eunhwang","geonyole","gihokim","gijung","gseok","haeem","hchin","hdoo","hisong","hocjeong","hoysong","huylee","hwasong","hyebinle","hyenchoi","hyeojeon","hyeyeom","hyunahn","hyungyki","hyunjiki","inam","iyeo","jacha","jaegbae","jaehukim","jaemjeon","jahong","jajo","jakim","jehbae","jemoon","jheo","jihamoon","jihwkim2","jimjeong","jinkwon","jinsecho","jinseo","jinyjeon","jishin","jisopark","joojeon","joonchoi","juheelee","juhyekim","junghule","junhoh","junkwak","junlee","junmin","junseyun","jupyo","kchoo","keunykim","kjung","ksuh","kyouhele","minju","mku","myeochoi","sanbaek","sangseo","sangwook","sejjeong","seku","seojang","seokjile","seongkim","seongmip","seonhwan","seoyokim","seungjo","siyukim","sooslee","ssohn","sunghyki","sunhnoh","suwi","taegkang","taehykwo","taejikim","taepark","wonhseo","woonhan","wooslee","wsunwoo","yeoju","yeojukim","yeonlee","yerpark","yikim2","yokoh","younam","younhbae","yuhjeon","yuhyoon","yuna","yunseo","yutsong","ahrelee"]

try{if (tick ==  5) here=document.location.href.match(/.+\/users\/(.+)/)[1];
	if (tick == 10) next=cadet[cadet.indexOf(here)+1];
	if (tick == 20) localStorage[here] = document.querySelector('html').innerText.includes("lackhole")
	if (tick == 30) document.location.href = document.location.href = document.location.href.replace(/.+?users\/(.+)/, next);
tick++;}
catch{tick = 0}


/* 마지막 문장만 수정하면 됨 */
try { div.innerText = $(".console-view-pinpane").shadowRoot.querySelector(".console-pin-preview").innerText; div.style.fontSize = "20px"; div.style.backgroundColor="RGB(255, 255, 255, 1)"; div.style.color="black"} catch { div = document.createElement('div'); div.style.width="100%"; div.style.height="100%"; div.style.zIndex="99999"; if(document.title.includes("DevTools")) $('.widget').appendChild(div); } $('[href*=slot]').parentNode.parentNode.parentNode.querySelector('.h-full').innerText