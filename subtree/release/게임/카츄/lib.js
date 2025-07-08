const { abs, sign, floor, random } = Math;

Q = (x, y=document) => y.querySelector(x);
QQ = (x, y=document) => [...y.querySelectorAll(x)];
Elem = (tag, cName=null) => { let e = document.createElement(tag); if(cName) e.className = cName; return e };

vector = (n, f=()=>0) => [...Array(n)].map((_, i) => f(i));
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

debug = x => Q('#debug').innerHTML = x;
