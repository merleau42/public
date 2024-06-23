#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// size_t Exist[67108864];

int a()
{
	printf("a\n");
	return 1;
}

int main()
{
	if ("b" && a())
		printf("b");
	else
		printf("c");
}

// // 1바이트보다 작은 자료형으로 계수 정렬하기
// 142를 존재 명부에 등록하려면? 64로 나눈 몫(2), 나머지(14)
// Exist[2] = Exist[2] | (size_t)(-1) >> 14;

// 777을 존재 명부에 등록하려면? 64로 나눈 몫(12), 나머지(9)
// Exist[12] = Exist[12] | (size_t)(-1) >> 9;

// 등록된 숫자를 꺼내려면?
// size_t i;
// i = 0;