/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/05 19:16:29 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	int			check;

	if (fd < 0)
		return (0);
	check = 1;
	while (check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check < 0)
			return (0);
		buf[BUFFER_SIZE] = 0;
		// backup에 buf 이어붙이기
		
	}
}
