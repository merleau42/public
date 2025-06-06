
Q = (x, y=document) => y.querySelector(x);
QQ = (x, y=document) => [...y.querySelectorAll(x)];

range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a*1 + d * i * sign(l - a) : d * i * sign(a));
natural = (n, m=undefined) => m ? range(+n, (+m)+1) : range(1, (+n)+1);
vector = (n, f=()=>0) => [...Array(n)].map((_,i)=>f(i,n));
matrix = (rows, cols, f=()=>0) => vector(rows).map((_,i) => vector(cols).map((_,j) => f(i,j,rows,cols)));

randz = (min, max, arr=0) => arr ? range(arr).map(x => randz(min,max)) : floor(random() *(max - min + 1)) + min;
