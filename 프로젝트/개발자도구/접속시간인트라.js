[...document.querySelectorAll('.table-fixed')]
.map(table =>
    [
        table.querySelector('thead th').innerText
        ,[...table.querySelectorAll('button div')]
            .map(x=>x.getAttribute('style').match(/rgba?\((.+)\)/)[1].split(', ').with(1,'1').toSorted()[1]*86400)
            .filter(x=>x>0)
            .reduce((s,c,i,a)=>[a.length, s[1] + c], [0, 0])
    ]
)
.map(x=>`${x[0]}(${x[1][0]}d): ${Math.floor(x[1][1]/3600)}H${Math.floor(x[1][1]%3600/60)}`)