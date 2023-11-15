/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:59:35 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/03 16:55:49 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	find = (char)c;
	i = 0;
	while (s[i])
	{
		if ((char)s[i] == find)
			return ((char *)&s[i]);
		i++;
	}
	if (find == 0)
		return ((char *)&s[i]);
	return (0);
}
