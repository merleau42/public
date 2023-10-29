void rush(int x, int y)
{
	printf("\nrush(%d,%d)\n", x, y);
	int i;
	int put;
	i = 0;

	while (i++ < x * y)
	{
		put = 4;
		put += ((i - 1) % x > 0) + ((i - 1) % x == x - 1);
		put += -3 * ((i - 1) / x == 0) + 3 * ((i - 1) / x == y - 1);
		put += -(x == 1) - 3 * (y == 1);
		write(1, &"07894 6123"[put], 1); // numpad
		// write(1, &"0o-o| |o-o"[put], 1); // RUSH 00		oooo
		// write(1, &"0/*\\* *\\*/"[put], 1); // RUSH 01	hamburger
		// write(1, &"0ABAB BCBC"[put], 1); // RUSH 02		AACC
		// write(1, &"0ABCB BABC"[put], 1); // RUSH 03		ACAC
		// write(1, &"0ABCB BCBA"[put], 1); // RUSH 04		ACCA
		if (i % x == 0)
			printf("\n");
	}
}

int main()
{
	rush(1, 1);
	rush(1, 2);
	rush(1, 3);
	rush(1, 4);
	rush(2, 1);
	rush(3, 1);
	rush(4, 1);
	rush(2, 2);
	rush(2, 3);
	rush(2, 4);
	rush(3, 2);
	rush(3, 3);
	rush(3, 4);
	rush(4, 4);
	rush(5, 7);
}

/*

i					(i-1) / x			(i-1) % x			put
					알파				 베타
0x + 1				0					0					1
0x + 2~x-1			0					1~x-2				2
0x + x				0					x-1					3

1x + 1				1					0					4
1x + (2 ~ x - 1)	1					1~x-2				5
1x + x				1					x-1					6

2x + 1				2					0					4
2x + (2 ~ x - 1)	2					1~x-2				5
2x + x				2					x-1					6

...
...
nx + 1				n					0					4
nx + (2 ~ x - 1)	n					1~x-2				5
nx + x				n					x-1					6
...
...

막x + 1				막					0					7
막x + (2 ~ x - 1)	막					1~x-2				8
막x + x				막					x-1					9

막x + x	==	xy
막		==	y - 1

put 의 공식은?
베타가 0		이면 	4	 +	(알파가 0이면 -3)	+	(알파가 막이면 +3)
베타가 1~x-2	이면 	5	 +	(알파가 0이면 -3)	+	(알파가 막이면 +3)
베타가 x-1		이면 	6	 +	(알파가 0이면 -3)	+	(알파가 막이면 +3)

*/