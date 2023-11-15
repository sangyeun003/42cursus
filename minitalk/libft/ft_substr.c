/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:33:52 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/09 20:32:36 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	real_len;
	size_t	i;

	str_len = ft_strlen((char *)s);
	real_len = 0;
	if ((size_t)start < str_len)
	{
		while (s[(size_t)start + real_len] && real_len < len)
			real_len++;
	}
	str = (char *)malloc((real_len + 1) * sizeof(char));
	if (!(str))
		return (0);
	i = 0;
	while (i < real_len)
	{
		str[i] = (char)s[(size_t)start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
