/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:45:16 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/22 23:00:13 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tab[i] != 0)
	{
		if ((*f)(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

// int have_seven(char *arr)
// {
// 	while (*arr != '\0')
// 	{
// 		if (*arr == '7')
// 			return 1;
// 		arr++;
// 	}
// 	return 0;
// }

// // tab은 문자열을 원소로 갖는다
// // 건내받은 f에 의한 평가값이 1에 해당하는 tab의 원소의 갯수

// #include <stdio.h>
// int main()
// {
// 	int i=0;
// 	char* str[] = {"w7w", "1234", "5678", "0", "7", "77",
// "dffdsf", "asds7ad", "999", "xxx", "zz7", 0};
// 	while (str[i] != 0)
// 	{
// 		printf("%s has seven? %d\n", str[i], have_seven(str[i]));
// 		i++;
// 	}
// 	printf("\n\n%d", ft_count_if(str, have_seven));	
// }
