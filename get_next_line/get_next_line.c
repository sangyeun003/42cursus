/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/16 01:58:58 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<string.h>
#include	<stdio.h>
#include	<fcntl.h>

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;
	int			read_size;
// invalid input 처리
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (backup)
			backup = 0;
		return (0);
	}
// buf 동적할당
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		if (backup)
			backup = 0;
		return (0);
	}
// backup에 strjoin하기 위해 초기화해줌
	if (!backup)
	{
		backup = strdup("");
		if (!backup)
		{
			free(buf);
			return (0);
		}
	}
// 읽어오는 단계
	// printf("backup1: %s\n", backup);
	read_size = 1;
	while (!strchr(buf, '\n') && read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		// printf("read_size: %d\n", read_size);
		if (read_size < 0)
		{
			backup = 0;
			free(buf);
			return (0);
		}
		buf[read_size] = 0;
		backup = ft_strjoin(backup, buf);
		if (!backup)
		{
			backup = 0;
			free(buf);
			return (0);
		}
	}
	// printf("buf: %s\n", buf);
	free(buf);
	buf = 0;
	// printf("backup2: %s\n", backup);
// line에 backup값 다듬어서 저장하는 단계
	if (*backup == 0)
	{
		backup = 0;
		return (0);
	}
	line = strdup(backup);
	if (!line)
	{
		backup = 0;
		return (0);
	}
	if (strchr(line, '\n'))
		*(strchr(line, '\n') + 1) = 0;
	line = strdup(line);
	if (!line)
	{
		backup = 0;
		return (0);
	}
// backup에서 반환한 부분 삭제하는 단계 -> 문제!
	// printf("strchr: %s\n", strchr(backup, '\n'));
	if (strchr(backup, '\n'))
		backup = strchr(backup, '\n') + 1;
	else
		backup = 0;
	// printf("backup3: %s\n", backup);

	return (line);
}
