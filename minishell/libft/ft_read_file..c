/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file..c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:39:35 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 14:39:35 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_size;
	char	*str;

	str = ft_strdup("");
	if (str == FT_NULL)
		return (FT_NULL);
	while (TRUE)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(str);
			return (FT_NULL);
		}
		if (read_size == 0)
			break ;
		buf[read_size] = 0;
		str = gnl_strjoin_and_free(str, buf);
	}
	return (str);
}
