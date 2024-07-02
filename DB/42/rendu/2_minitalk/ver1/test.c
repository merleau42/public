#include "minitalk.h"
#include <string.h>
#include <stdio.h>

//: 1바이트보다 작은 자료형
int main() {
	byte	*bitstream;
	
	bitstream = (byte *) malloc(77777);
	ft_memset(bitstream, 0, 77777);

	bitstream[0] = bitstream[0] | 1 << 6;
	bitstream[0] = bitstream[0] | 0b100;

	ft_printf("%s\n", bitstream);
}

// 142를 존재 명부에 등록하려면? 64로 나눈 몫(2), 나머지(14)
// Exist[2] = Exist[2] | (size_t)(-1) >> 14;
// 777을 존재 명부에 등록하려면? 64로 나눈 몫(12), 나머지(9)
// Exist[12] = Exist[12] | (size_t)(-1) >> 9;
// 등록된 숫자를 꺼내려면?