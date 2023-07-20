/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/20 20:39:42 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*temp;
	char		*line;
	char		*buf;
	int			read_size;
// invalid input 처리
	if (fd < 0 || fd > 8192 || BUFFER_SIZE <= 0)
	{
		if (backup)
		{
			free(backup);
			backup = 0;
		}
		return (0);
	}
// buf 동적할당
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		if (backup)
		{
			free(backup);
			backup = 0;
		}
		return (0);
	}
// backup에 strjoin하기 위해 초기화해줌
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
		{
			free(buf);
			buf = 0;
			return (0);
		}
	}
// 읽어오는 단계
	read_size = 1;
	*buf = 0;	// 이거 안해주면 while 조건에서 strchr할 때 heap-buffer-overflow 남.
	while (!ft_strchr(buf, '\n') && read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(backup);
			free(buf);
			backup = 0;
			buf = 0;
			return (0);
		}
		buf[read_size] = 0;
		temp = ft_strdup(backup);
		if (!temp)
		{
			free(backup);
			free(buf);
			backup = 0;
			buf = 0;
			return (0);
		}
		free(backup);
		backup = ft_strjoin(temp, buf);
		free(temp);
		if (!backup)
		{
			free(buf);
			buf = 0;
			return (0);
		}
	}
	free(buf);
	buf = 0;
// line에 backup값 다듬어서 저장하는 단계
	if (*backup == 0)	// read한게 NULL뿐인 경우
	{
		free(backup);
		backup = 0;
		return (0);
	}
	temp = ft_strdup(backup);
	if (!temp)
	{
		free(backup);
		backup = 0;
		return (0);
	}
	if (ft_strchr(temp, '\n'))
		*(ft_strchr(temp, '\n') + 1) = 0;
	line = ft_strdup(temp);
	if (!line)
	{
		free(line);
		free(backup);
		line = 0;
		backup = 0;
		return (0);
	}
	free(temp);
// backup에서 반환한 부분 삭제하는 단계
	if (ft_strchr(backup, '\n'))
	{
		temp = ft_strdup(ft_strchr(backup, '\n') + 1);
		if (!temp)
		{
			free(line);
			free(backup);
			line = 0;
			backup = 0;
			return (0);
		}
		backup = ft_strdup(temp);
		if (!backup)
		{
			free(line);
			free(backup);
			line = 0;
			backup = 0;
			return (0);
		}
	}
	else
	{
		free(backup);
		backup = 0;
	}

	return (line);
}
