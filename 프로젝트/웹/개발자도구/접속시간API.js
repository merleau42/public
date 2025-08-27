function bc(flag="d", date1="2000-00-00", date2="2099-00-00") {
    try {
    if (flag == "d" && date1 == "2000-00-00" && date2 == "2099-00-00")
        flag = 'All';
    else if (flag == 'd')
        flag = (date1.slice(2)+','+date2.slice(2)).replace(/-/g,'').replace(/,/,'ㅡ') + ' ';
    else if (flag == 'm' && (1 <= date1 && date1 <= 12) && date2 == "2099-00-00") {
        flag = ['Nul','Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec'][date1];
        date2 = `2024-${date1.toString().padStart(2,'0')}-31`;
        date1 = `2024-${date1.toString().padStart(2,'0')}-00`;
    }
    else if (flag == 'y' && (2000 <= date1 && date1 <= 2099) && date2 == "2099-00-00") {
        flag = date1.toString();
        date2 = `${date1.toString()}-12-31`;
        date1 = `${date1.toString()}-00-00`;
    }
    else
        return "bc()__All,  bc('d','BEGIN','END')__yyyy-mm-dd,  bc('m', MONTH)__1~12,  bc('y', YEAR)__but only 2024";
    get = JSON.parse( document.querySelector('pre').innerText );
    return keys(get).filter(x => date1<=x && x<=date2)
        .map(x => get[x].split(':').reduce((s,c)=>s*60 + c*1))
        .reduce((s,c,i,a) => [a.length, s[1] + c/3600], [0, 0])
        .reduce((s,c,i) => [...s, i==0 ? c : [c - c % 1, Math.floor(c % 1 * 60)]].flat(), [])
        .reduce((s,c,i,a) => `${flag}(${a[0]}d): ${a[1]}H${a[2]}`)
    }
    catch {
        return "bc()__All,  bc('d','BEGIN','END')__yyyy-mm-dd,  bc('m', MONTH)__1~12,  bc('y', YEAR)__but only 2024";
    }
}