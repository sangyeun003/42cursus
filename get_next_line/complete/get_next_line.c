/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/21 02:23:03 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

void	ft_free_two_str(char **str1, char **str2)
{
	if (str1 != str2)
	{
		free(*str1);
		free(*str2);
		*str1 = 0;
		*str2 = 0;
	}
	else
	{
		free(*str1);
		*str1 = 0;
	}
}

int	ft_initial_setting(int fd, char **backup, char **buf)
{
	if (fd < 0 || fd > 8192 || BUFFER_SIZE <= 0)
	{
		if (*backup)
			ft_free_two_str(backup, backup);
		return (0);
	}
	*buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buf)
	{
		if (*backup)
			ft_free_two_str(backup, backup);
		return (0);
	}
	if (!*backup)
	{
		*backup = ft_strdup("");
		if (!*backup)
		{
			ft_free_two_str(buf, buf);
			return (0);
		}
	}
	return (1);
}

int	ft_read(int fd, char **backup, char **buf, int read_size)
{
	char	*temp;

	while (!ft_strchr(*buf, '\n') && read_size != 0)
	{
		read_size = read(fd, *buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			ft_free_two_str(backup, buf);
			return (0);
		}
		(*buf)[read_size] = 0;
		temp = ft_strdup(*backup);
		ft_free_two_str(backup, backup);
		if (!temp)
			return (0);
		*backup = ft_strjoin(temp, *buf);
		if (!*backup)
		{
			ft_free_two_str(&temp, buf);
			return (0);
		}
		free(temp);
	}
	return (1);
}

int	ft_make_return_value(char **backup, char **line)
{
	char	*temp;

	if (**backup == 0)
	{
		ft_free_two_str(backup, backup);
		return (0);
	}
	temp = ft_strdup(*backup);
	if (!temp)
	{
		ft_free_two_str(backup, backup);
		return (0);
	}
	if (ft_strchr(temp, '\n'))
		*(ft_strchr(temp, '\n') + 1) = 0;
	*line = ft_strdup(temp);
	if (!*line)
	{
		ft_free_two_str(&temp, backup);
		return (0);
	}
	free(temp);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;

	if (!ft_initial_setting(fd, &backup, &buf))
		return (0);
	*buf = 0;
	if (!ft_read(fd, &backup, &buf, 1))
	{
		ft_free_two_str(&buf, &buf);
		return (0);
	}
	ft_free_two_str(&buf, &buf);
	if (!ft_make_return_value(&backup, &line))
		return (0);
	if (!ft_refine_backup(&backup, &line))
		return (0);
	return (line);
}
