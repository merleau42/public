int math()
{
	// N이 2의 제곱수인지
	if (n == 0) return (0);
	while (n % 2 == 0) n /= 2;
	return (n == 1);
	
	// N의 소수 판정
	i = 2;
	while (i < n)	if (!(n % i++))	 return (0);
	return (1);
	
	// N을 소인수 분해
	prime = 2;
	while (n > 1)
	{
		if (n % prime == 0)
		{
			printf("%d", prime);
			n /= prime;
			if (n > 1) printf("*");
			prime--;
		}
		prime++;
	}
	
	// 최대 공약수
	i = nb;
	while (i > 0)
	{
		if (a % i == 0 && b % i == 0) return i;
		i--;
	}
	return 1;
	
	// 최소 공배수
	if (a * b == 0) 	return (0);
    if (a > b)			d = (a / 2) + 1;
    else				d = (b / 2) + 1;
    while (!((a % d) == 0 && (b % d) == 0))  d--;
    return (a * b / d);
	
	// 비트 절반으로 나누어 교환
	r = (ch >> 4) | (ch << 4);
	
	// 비트 앞뒤 거꾸로
	r = 0;
	while (bits--)
	{
		r = (r << 1) | (ch & 1)
		ch >> 1;
	}
	
	// 배수 판정
	if (number % 3 == 0 && number % 5 == 0)	write(1, "fizzbuzz", 8);
	else if (number % 3 == 0)	write(1, "fizz", 4);
	else if (number % 5 == 0)	write(1, "buzz", 4);
	else						ft_putnbr(number);
}