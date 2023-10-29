int	ascii()
{
	int	i;
	int *str; // 외부 입력을 이용하는 경우, str[i] 대신에 argv[n][i] 
	
	i = 0;
	while (str[i] != '\0')	// 문자열 탐색
	{
		ch = str[i];
		if ('A' <= ch && ch <= 'Z')	ch += 32;	// 대문자만 소문자로
		if ('a' <= ch && ch <= 'z')	ch -= 32;	// 소문자만 대문자로
		
		if (('A' <= ch && ch <= 'Z')
			|| ('a' <= ch && ch <= 'z'))		// 알파벳인가?

		if ('0' <= ch && ch <= '9');			// 숫자인가?
		if (ch == ' ' || ch == '\t');			// 공백인가?
		if (32 <= ch && ch <= 126);				// 출력가능 문자인가?
		
		// rot13 (else if해서 중복 할당 방지)
			 if (('A' <= ch && ch <= 'M') || ('a' <= ch && ch <= 'm')) ch += 13;
		else if (('N' <= ch && ch <= 'Z') || ('n' <= ch && ch <= 'z')) ch -= 13;
		
		// 아스키 뒤집기 (else if해서 중복 할당 방지)
			 if ('A' <= ch && ch <= 'Z')	ch = 64 + (27-ch);
		else if ('a' <= ch && ch <= 'z')	ch = 96 + (27-ch);
		
		// 알파벳 순서값
			 if ('A' <= c && c <= 'Z')		order = ch - 64;
		else if ('a' <= c && c <= 'z')		order = ch - 96;
		
		i++;
	}
	return (1);
}