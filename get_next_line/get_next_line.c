/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/10 22:04:08 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<string.h>

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			read_size;
	char		*error_check;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size < 0)
		return (0);
	buf[read_size] = 0;
	while (!strchr(buf, '\n'))
	{
		error_check = ft_strjoin(line, buf);
		if (!error_check)
			return (0);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (0);
		buf[read_size] = 0;
	}
	return ((char *)line);
}
	// char		*find;

	// buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	// if (!buf)
	// 	return (0);
	// if (fd < 0 || BUFFER_SIZE <= 0)
	// 	return (0);
	// read_size = read(fd, buf, BUFFER_SIZE);
	// if (read_size < 0)
	// {
	// 	free(buf);
	// 	return (0);
	// }
	// buf[read_size] = 0;
	// while (!strchr(buf, '\n'))
	// {
	// 	ft_strjoin(backup, buf);
	// 	read_size = read(fd, buf, BUFFER_SIZE);
	// 	if (read_size < 0)
	// 	{
	// 		free(buf);
	// 		free(backup);
	// 		return (0);
	// 	}
	// 	buf[read_size] = 0;
	// }
	// find = strchr(buf, '\n');
	// if (find)
	// {
	// 	*(find + 1) = 0;
	// 	ft_strjoin(backup, buf);
	// }
	// return (strdup((char *)backup));