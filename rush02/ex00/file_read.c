/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:20:10 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/20 18:57:44 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/* numbers.dict 읽어와서 저장하는 함수 */
char	*ft_open_read(void)
{
	int		fd;
	char	*buffer;
	int		rd_size;

	buffer = malloc(sizeof(char) * BUFF_SIZE);  // 64bit 최대값인 2048만큼 할당
	if (!buffer)	// 공간 할당 에러
	{
		write(1, "Buffer Error\n", 14);
		return (0);
	}
	fd = open("numbers.dict", O_RDONLY);	// 읽기 전용으로 파일 열음. <fcntl.h>
	if (fd == -1)	// 파일 open 에러
		write(1, "File Open Error\n", 17);
	else
	{
		rd_size = read(fd, buffer, BUFF_SIZE);	// 버퍼 사이즈만큼 읽어옴. 이때 버퍼가 최대니까 전체 다 읽어옴.
		if (rd_size == -1)	// 파일 read 에러
			write(1, "File Read Error\n", 17);
		else
			close(fd);	// 파일 닫음 -> [!!error!!] else문 밖으로 빼줘야 함
	}
	return (buffer);
}

/* 새로운.dict 읽어와서 저장하는 함수 */
char	*ft_open_read_argv(char *new_dict)
{
	int		fd;
	char	*buffer;
	int		rd_size;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (!buffer)
	{
		write(1, "Buffer Error\n", 14);
		return (0);
	}
	fd = open(new_dict, O_RDONLY);
	if (fd == -1)
		write(1, "File Open Error\n", 17);
	else
	{
		rd_size = read(fd, buffer, BUFF_SIZE);
		if (rd_size == -1)
			write(1, "File Read Error\n", 17);
		else
			close(fd);
	}
	return (buffer);
}
