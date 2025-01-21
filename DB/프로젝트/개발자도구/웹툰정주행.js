try {if (n%10==0) window.scrollTo(0, 1+(imgs.map(x=>x.offsetTop).toSpliced(0,0,0)
.reduce((s,c,i,a)=>i>0 ? [ ...s, [a[i-1], Math.ceil((a[i-1]+a[i])/2)] ] : s,[])
.flat().find(top => window.scrollY < top)??imgs.at(-1).offsetTop));
if (n > imgs.length * 20) document.querySelector('button.link_next').click();
n++} catch {n=0; imgs=[...document.querySelectorAll('img[id*=content_image]')]}