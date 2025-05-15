/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:09:58 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/19 02:10:28 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i >= n)
			return (0);
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}


// // 태건 형님 방식 비교
// #include <stdio.h>
// #include <string.h>
// int	ft_strncmp(char *s1, char *s2, size_t n)
// {
// 	unsigned int	target;

// 	if (n == 0)
// 		return (0);
// 	target = 0;
// 	while (target + 1 < n && s1[target] != '\0' && s1[target] == s2[target])
// 	{
// 		target++;
// 	}
// 	return (s1[target] - s2[target]);
// }

// int main()
// {
// 	//	예쁜 색깔 넣기 (%s ~ %s)
// 	char *DEFAULT = "\033[0;00m";
// 	char *YELLOW = "\033[0;32m";
// 	char *RED = "\033[0;31m";

// 	//	문자열 셋팅
// 	char *a[99] = {"dragon", "d", "dragon", "dragon", "dragon", "dragonball", "dragonfly", "dragonball", "dragonfall", "dragon", "dream", "ball", "fall", "dragon", "d", "\0", "\0", "\0"};
// 	char *b[99] = {"dragon", "dragon", "dragonball", "dragonfly", "d", "dragon", "dragon", "dragonfall", "dragonball", "dream", "dragon", "fall", "ball", "\0", "\0", "dragon", "d", "\0"};

// 	// strNcmp
// 	for (int i=0; a[i]!=0; i++){
// 		printf("%s\n\"%s\"\n\"%s\"%s\n", YELLOW, a[i], b[i], DEFAULT);
// 		printf("N:\tstrncmp\t\tft\n");

// 		for (unsigned int n=0; n<=(1<<29); n++)
// 		{
// 			int left  = strncmp(a[i], b[i], n);
// 			int right = ft_strncmp(a[i], b[i], n);

// 			if (left != right)
// 				printf("%s%d:\t%d\t\t%d%s\n", RED, n, left, right, DEFAULT);
// 		}
// 	}
// }