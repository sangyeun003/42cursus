/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/06 23:39:59 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"get_next_line.h"
#include	<string.h>

// #define BUFFER_SIZE 3

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	int			check;
	char		*find;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = 0;
	while (!strchr(backup, '\n') || !check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check < 0)
			return (0);
		buf[check] = 0;
		// backup에 buf 이어붙이기
		if (!backup)
			backup = strdup(buf);
		else
			ft_strjoin(backup, buf);
	}
	ft_strjoin(backup, "\0");
	find = strchr(backup, '\n');
	if (!find)
		*(find + 1) = 0;
	backup = strdup(backup);
	return ((char *)backup);
}
