[...document.querySelectorAll('#container.ytd-playlist-video-renderer')]
.reduce((s,c,i)=>
    [...s,
        [
            c.querySelector('#video-title').innerText,
            sec=c.querySelector('#time-status').innerText.split(":").reduce((s,c)=>s*60+c*1),
            Math.round( (s[i][2]+sec/60)*100 )/100
        ]
    ]
    ,[[0,0,0]])
// 유튜브 재생목록 러닝타임
// [영상 제목, 시간(초), 누적 시간(분)]