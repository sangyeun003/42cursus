/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:15:02 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/09 20:34:09 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (!(ft_strlen(n)))
		return (h);
	if (ft_strlen(h) < ft_strlen(n))
		return (0);
	while (haystack[i + ft_strlen(n) - 1] && i + ft_strlen(n) - 1 < len)
	{
		if (!(ft_strncmp(h + i, n, ft_strlen(n))))
			return (h + i);
		i++;
	}
	return (0);
}
