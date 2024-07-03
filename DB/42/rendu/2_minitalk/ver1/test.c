#include "minitalk.h"
#include <string.h>
#include <stdio.h>

int main() {
	byte	*bytestream;

	bytestream = (byte *)malloc(77777);
	ft_memset(bytestream, 0, 77777);

	// 'Z' == 0b01011010;
	bytestream[0] = (bytestream[0] << 1) + 0;
	bytestream[0] = (bytestream[0] << 1) + 1;
	bytestream[0] = (bytestream[0] << 1) + 0;
	bytestream[0] = (bytestream[0] << 1) + 1;
	bytestream[0] = (bytestream[0] << 1) + 1;
	bytestream[0] = (bytestream[0] << 1) + 0;
	bytestream[0] = (bytestream[0] << 1) + 1;
	bytestream[0] = (bytestream[0] << 1) + 0;

	write(1, bytestream)
}

// 142를 존재 명부에 등록하려면? 64로 나눈 몫(2), 나머지(14)
// Exist[2] = Exist[2] | 0x8000000000000000 >> 14;
// 777을 존재 명부에 등록하려면? 64로 나눈 몫(12), 나머지(9)
// Exist[12] = Exist[12] | 0x8000000000000000 >> 9;
// 등록된 숫자를 꺼내려면?
