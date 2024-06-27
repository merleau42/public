/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:07:21 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/24 11:07:22 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 호출할 때마다 ---> fd에 해당하는 텍스트 파일을 한 줄씩 읽고 리턴
// 읽을 내용이 없거나 오류시 NULL 리턴
// 반환되는 각각의 줄은 파일 끝에 도달하여 \n 문자가 없는 경우를 제외하고는 \n문자를 포함
// 컴파일시 -D BUFFER_SIZE=n 옵션 넣을 수 있어야함. read의 버퍼 크기.
// 보너스: fd마다 라인 읽기의 진행 현황을 보존하고, fd를 변경해가면서 호출할 수 있어야함
// 허용함수: read, malloc, free

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	int		remain;					// 불러오기 성공한 길이 (SIZE 이하)
	static	char	buf[BUFFER_SIZE + 1];	// 불러오기 성공한 문자열
	static	char	*line;					// 현재 만들고있는 라인
	char			*endl;					// 개행 문자 발생 위치 (0 ~ SIZE)
	char			*tmp;

	// 버퍼를 다 비웠거나 (퍼펙트 클리어), 최초의 호출이라면, 새로운 read
	if (buf[0] == 0)
	{
		remain = read(fd, buf, BUFFER_SIZE);
		if (remain <= 0) // remain이 -1 이거나 또다시 0이라면 파일의 끝.
			return (void *) 0;
		line = ft_strjoin("","");
	}
	endl = ft_strchr(buf, '\n');
	if (endl) // 버퍼에 개행 문자가 있다면 라인을 하나 이상 불러왔음.(read: 1/1.2/3/3.5/1+EOF)
	{
		tmp = ft_strjoin(line, ft_substr(buf, 0, endl - buf + 1)); // 우선 하나의 라인을 제출.
		free (line);
		line = tmp;
		remain = remain - (endl - buf + 1);
		ft_memmove(buf, buf + endl, );
		ft_memset(remain, 0, BUFFER_SIZE - remain);
		return tmp;
	}
	if (!endl) // 개행 문자가 없다면 라인을 덜 불러왔거나, 파일의 끝에 가까워짐.
	{
		// 라인을 덜 불러옴	--- remain == BUFFER_SIZE
		// 파일의 끝에 가까워짐	--- 0 < remain < BUFFER_SIZE
		tmp = ft_strjoin(line, ft_substr(buf, 0, remain));
		free (line);
		line = tmp;
		ft_memmove(buf, buf + endl);
		ft_memset(buf + endl, 0, BUFFER_SIZE - endl);
		remain = 0;
		endl = ft_strchr(buf, '\n');
	}
	ft_memset(buf, 0, BUFFER_SIZE + 1);
}

int main()
{
	int fd;
	char buff[100];
	
	fd = open("sample.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close (fd);

	return 0;
}
