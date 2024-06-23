/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 17:15:43 by keunykim         ###   ########.fr       */
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
	static char	*storage;
	char		*leftovers;
	char		*piece;
	size_t		len;
	ssize_t		shovel; // 파일은 '파여질' 이라는 뜻. that would be shovled. 
	char		*buff;
	char		*tmp;

	buff = (char *) malloc(((size_t)BUFFER_SIZE + 1) * sizeof (char));
	shovel = read(fd, buff, BUFFER_SIZE);
	while (shovel > 0) // 파일의 끝이거나(0) 오류가 발생하면(-1) 삽질 종료
	{
		// shovel = read(fd, buff, BUFFER_SIZE);
		// if (shovel < 1) // 파일의 끝이거나(0) 오류가 발생하면(-1) 삽질 종료
			// break;
		buff[shovel] = '\0'; // 버퍼의 유효한 분량만 이어붙이기 위하여.
		tmp = ft_strjoin(storage, buff);
		free(storage);
		storage = tmp;
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	free(buff);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (storage == NULL)
		storage = ft_strjoin("","");
	ft_read_fd(fd, storage);
	if (ft_strchr(storage, '\n'))
		len = ft_strchr(storage, '\n') - storage + 1;
	else
		len = fr_strlen(storage);
	piece = ft_substr(storage, 0, len);
	leftovers = ft_substr(storage, len, ft_strlen(storage) - len);
	free(storage);
	storage = leftovers;
	return (piece);
}

int main()
{
	int		fd;
	char	*line;
	
	fd = open("sample", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close(fd);
}