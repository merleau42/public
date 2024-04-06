[가정0] M//N == M을 N으로 나눈 몫
[가정1] NS > M
[가정2] M//N >= S (귀류법)

[0▶]
M = NP + R
M//N = P

[2▶]
M//N >= S
P >= S
NP >= NS
NP + R >= NS + R
M >= NS + R

[2+1▶]
NS > M
NS > M >= NS + R
NS > NS + R
0 > R 으로 모순

[결론] NS > M 이면, M//N < S

























[가정0] M//N == M을 N으로 나눈 몫
[가정1] NS = M

[1▶]
M//N
= (NS)//N
= S

[결론] NS = M 이면, M//N = S


















[가정0] M//N == M을 N으로 나눈 몫
[가정1] NS < M

[0▶]
M = NP + R
M//N = P
M/N = P + R/N

[1▶]
NS < M
S < M/N
S < (NP + R)/N
S < P + R/N
S < M//N + R/N

(경우1: R = 0) 
	S < M//N

(경우1: R > 0)
	S < M//N + 0.XXX

	부등식을 만족하는 '정수' S의 최댓값은?
	S = M//N
	부등식을 만족하는 '정수' S의 다른 사례는?
	S < M//N

[결론] NS < M 이면, S <= M//N


따라서,
N: Nmemb
S: Size
M: MAX 라고 할때 다음이 성립한다

NS  > M 이면, M//N < S
NS <= M 이면, M//N >= S

다시 말해서,
N * S가 오버플로우를 일으킨다면, if (M//N < S) 가 참이므로 NULL 반환
N * S가 얌전한 값이라면, if (M//N < S) 가 거짓이므로 if문을 패스한다














/*
IF (M//N<S) OVERFLOW;


[1] NS < M
[2] M//N < S

[0>]
M = NP + R
M//N = P

[0>]
M//N <= M/N
P <= M/N

[1>]
NS < M
S < M/N

[2>]
M//N < S

[2+1>]
M//N < S < M/N
M//N < M/N
P < M/N
NP < M
NP + R < M + R
M < M + R
0 < R
M은 N으로 나누어 떨이지지 않는다
M = NP + R
M/N = P + R/N
M/N = M//N + R/N
M/N - R/N = M//N
M/N - R/N < S


*/