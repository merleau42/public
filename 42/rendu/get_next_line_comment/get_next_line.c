/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 20:58:34 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 호출할 때마다 ---> fd에 해당하는 텍스트 파일을 한 줄씩 읽고 리턴
//: 읽을 내용이 없거나 오류시 NULL 리턴
// 반환되는 각각의 줄은 파일 끝에 도달하여 \n 문자가 없는 경우를 제외하고는 \n문자를 포함
// 컴파일시 -D BUFFER_SIZE=n 옵션 넣을 수 있어야함. read의 버퍼 크기.
// 보너스: fd마다 라인 읽기의 진행 현황을 보존하고, fd를 변경해가면서 호출할 수 있어야함
// 허용함수: read, malloc, free

#include "get_next_line.h"
#include <stdio.h> // 지우시오

char	*get_next_line(int fd)
{
	static char	*storage;
	ssize_t		shovel; // 파일은 '파여질' 이라는 뜻. that would be shovled. 한번에 파낸 분량.
	char		*cart;
	char		*tmp;
	char		*leftovers;
	char		*piece;
	size_t		len;

	//: static int	calln = 0;
	//: int			iter=0;

	//: calln++;
	if (fd < 0 || BUFFER_SIZE <= 0) // 비정상적인 호출시 종료.
		return (NULL);
	if (storage == NULL) // 함수의 최초 호출시 스토리지 생성.
		storage = ft_strjoin("","");
	cart = (char *) malloc(((size_t)BUFFER_SIZE + 1) * sizeof (char)); // 이번 호출에서 사용될 버퍼를 생성. (광부)
	shovel = read(fd, cart, BUFFER_SIZE); // BUFFER_SIZE 만큼 파일에서(광산) 퍼오기 시도. BUFFER_SIZE는 카트의 최대 용량.
	while (shovel > 0) // 파일끝(0) 오류발생(-1) 개행문자발견시(\n) 퍼오기 종료.
	{
		cart[shovel] = '\0'; // 파일의 분량이 BUFFER_SIZE 보다 모자를 수도 있음. (자투리)
		tmp = ft_strjoin(storage, cart); // 퍼온 만큼 저장고에 쌓기.
		free(storage);
		storage = tmp;
		if (ft_strchr(cart, '\n')) // 방금 부어놓고 온 카트에 개행문자가 있었으면 종료.
			break;
		// printf("[call:%d   iter:%d   cart:%s   storage: %s]\n", calln, iter, cart, storage);
		shovel = read(fd, cart, BUFFER_SIZE); // 계속되는 삽질과 운반.
		//: iter++;
	}
	// printf("[call:%d   iter:E   cart:%s   storage: %s]\n", calln, cart, storage);
	free(cart); // 광부의 오늘 일감 종료.
	if (shovel == -1) // 오늘 일진이 사나웠다면, 이 현장 다시 안옴.
		return (NULL);
	if (ft_strchr(storage, '\n')) // 저장고에 개행문자가 있다면, len = 개행문자까지 길이
		len = ft_strchr(storage, '\n') - storage + 1;
	else
		len = ft_strchr(storage, '\0') - storage;//저장고에 개행문자가 없다면, len=파일끝까지 길이 (짜투리)
	piece = ft_substr(storage, 0, len);
	leftovers = ft_substr(storage, len, ft_strchr(storage, '\0') - storage - len);
	free(storage);
	storage = leftovers;
	// printf("[call:%d   iter:X   cart:--   storage: %s]\n", calln, storage);
	// printf("LINE: %s\n\n", piece);
	return (piece);
}