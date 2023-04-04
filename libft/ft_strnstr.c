/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:15:02 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/04 21:42:32 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_strncmp(char *s1, char *s2, size_t len)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == len)
		i--;
	return (s1[i] - s2[i]);
}

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	same;

	
}
