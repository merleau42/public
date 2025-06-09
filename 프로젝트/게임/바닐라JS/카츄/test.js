const { abs, sign, floor, random } = Math;

Q = (x, y=document) => y.querySelector(x);
QQ = (x, y=document) => [...y.querySelectorAll(x)];
Elem = (tag, cName=null) => { let e = document.createElement(tag); if(cName) e.className = cName; return e};

range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a*1 + d * i * sign(l - a) : d * i * sign(a));
natural = (n, m=undefined) => m ? range(+n, (+m)+1) : range(1, (+n)+1);
vector = (n, f=()=>0) => [...Array(n)].map((_,i)=>f(i,n));
matrix = (rows, cols, f=()=>0) => vector(rows).map((_,i) => vector(cols).map((_,j) => f(i,j,rows,cols)));

debug = (x) => Q('#debug').innerHTML = x;

/////////////////////////////////////////////////////테스트

randz = (min, max, num = 0, dupl = true) => {
	if (!num)
		return floor(random() * (max - min + 1)) + min;
	if (dupl)
		return vector(num, () => randz(min, max));
    const set = new Set();
    while (set.size < num && set.size < abs(max - min) + 1)
        set.add(randz(min, max));
    return [...set];
};


console.log(  randz(3, 7, 10, 1)  );
console.log(  randz(3, 7, 10, 0)  );