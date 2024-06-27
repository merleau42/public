# 쉘 스크립트
curl --request GET --url 'https://solved.ac/api/v3/problem/show?problemId=1234' --header 'Accept: application/json'


# 자바스크립트로 파싱
# 번호, 제목, 티어, 태그, 정답자, 기여자
p = JSON.parse(document.querySelector('pre').innerText);
[p.problemId, p.titles[0]['title'], p.level, p.tags.map(x=>x['key']).join(', '), p.acceptedUserCount, p.votedUserCount]