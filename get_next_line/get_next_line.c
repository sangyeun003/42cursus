/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/20 21:27:51 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

void	ft_free_one_str(char **str)
{
	free(*str);
	*str = 0;

	return ;
}

void	ft_free_two_str(char **str1, char **str2)
{
	free(*str1);
	free(*str2);
	*str1 = 0;
	*str2 = 0;
}

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
			ft_free_one_str(&backup);
		return (0);
	}
// buf 동적할당
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		if (backup)
			ft_free_one_str(&backup);
		return (0);
	}
// backup에 strjoin하기 위해 초기화해줌
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
		{
			ft_free_one_str(&buf);
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
			ft_free_two_str(&backup, &buf);
			return (0);
		}
		buf[read_size] = 0;
		temp = ft_strdup(backup);
		ft_free_one_str(&backup);
		if (!temp)
		{
			ft_free_two_str(&backup, &buf);
			return (0);
		}
		backup = ft_strjoin(temp, buf);
		if (!backup)
		{
			ft_free_two_str(&temp, &buf);
			return (0);
		}
		free(temp);
	}
	ft_free_one_str(&buf);
// line에 backup값 다듬어서 저장하는 단계
	if (*backup == 0)	// read한게 NULL뿐인 경우
	{
		ft_free_one_str(&backup);
		return (0);
	}
	temp = ft_strdup(backup);
	if (!temp)
	{
		ft_free_one_str(&backup);
		return (0);
	}
	if (ft_strchr(temp, '\n'))
		*(ft_strchr(temp, '\n') + 1) = 0;
	line = ft_strdup(temp);
	if (!line)
	{
		ft_free_two_str(&temp, &backup);
		return (0);
	}
	free(temp);
// backup에서 반환한 부분 삭제하는 단계
	if (ft_strchr(backup, '\n'))
	{
		temp = ft_strdup(ft_strchr(backup, '\n') + 1);
		if (!temp)
		{
			ft_free_two_str(&backup, &line);
			return (0);
		}
		free(backup);
		backup = ft_strdup(temp);
		free(temp);
		if (!backup)
		{
			ft_free_one_str(&line);
			return (0);
		}
	}
	else	// 끝에 개행 없고 EOF
		ft_free_one_str(&backup);
	return (line);
}
