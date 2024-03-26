// cc -x c 옵션으로, 확장자없는 파일도 C파일로 간주해서 컴파일 가능
#include <stdio.h>
#include <stdlib.h>

// 조건식에 들어가는 것
is(OZ, HEAD){
	return clone(context, OZ, HEAD);
}

// 행동 단위
Do(y){
	delete (context, y);
}

int heads[6][2] = {
	{pr, 0}, {pi, 32}, {nr, 48}, {ni, 56},{tr, 60}, {ti, 62}
};
 
// 코드 블럭 일반화
F(OZ, i){
	if (is(OZ, &heads[i, 0]))
	{
		Do(ZR); // 고정 작업
		Do(ZI); // 고정 작업

		Tasks(heads[i, 1]); // 헤드에 따라서 달라지는 작업 목록
		return true;
	}
}

Tasks(code){
	if (code & 32) Do(pr);
	if (code & 16) Do(pi);
	if (code &  8) Do(nr);
	if (code &  4) Do(ni);
	if (code &  2) Do(tr);
	if (code &  1) Do(ti);
}


// 코드 블럭 일반화
int heads[6][2] = {
	{pr, 0}, {pi, 32}, {nr, 48}, {ni, 56},{tr, 60}, {ti, 62}
};

F(OZ, i){
	if (clone(context, OZ, &heads[i, 0]))
	{
		code = heads[i, 1];
		if (     1    ) delete (context, zr);
		if (     1    ) delete (context, zi);
		if (code &  32) delete (context, pr);
		if (code &  16) delete (context, pi);
		if (code &   8) delete (context, nr);
		if (code &   4) delete (context, ni);
		if (code &   2) delete (context, tr);
		if (code &   1) delete (context, ti);
		return true;
	}
}

// 코드 블럭을 다음과 같이 쓸 수 있음
F(1, 0);
F(1, 1);
F(0, 2);
F(0, 3);
F(0, 4);
F(0, 5);


//// 헤드에 따른 작업 대조표 (세로:헤드, 가로:일감)
//        pr   pi   nr   ni   tr   ti
//&pr	  0    0    0    0    0    0
//&pi     1    0    0    0    0    0
//&nr     1    1    0    0    0    0
//&ni     1    1    1    0    0    0
//&tr     1    1    1    1    0    0
//&ti     1    1    1    1    1    0


// 헤드에 따른 작업 대조표 (세로:헤드, 가로:일감)
        pr   pi   nr   ni   tr   ti
&pr	    1    1    0    1    0    0
&pi     0    0    1    0    1    1
&nr     1    0    0    1    0    0
&ni     0    0    1    0    0    1
&tr     0    0    1    1    0    1
&ti     1    1    0    0    1    1

enum taskNo
{
	PR = 32,
	PI = 16,
	NR = 8,
	NI = 4,
	TR = 2,
	TI = 1
}

// 코드 블럭
F(OZ, *head, code){
	if (clone(context, OZ, head))
	{
		if (     1    ) delete (context, zr);
		if (     1    ) delete (context, zi);
		if (code &  32) delete (context, pr);
		if (code &  16) delete (context, pi);
		if (code &   8) delete (context, nr);
		if (code &   4) delete (context, ni);
		if (code &   2) delete (context, tr);
		if (code &   1) delete (context, ti);
		return true;
	}
}

// 코드 블럭을 다음과 같이 쓸 수 있음
F(1, &pr, PR + PI + NI);
F(1, &pi, NR + TR + TI);
F(0, &nr, PR + NI);
F(0, &ni, NR + TI);
F(0, &tr, NR + NI + TI);
F(0, &ti, PR + PI + TR + TI);


