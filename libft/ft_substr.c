/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:33:52 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/29 11:59:01 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	str_len;
	unsigned int	real_len;
	unsigned int	i;

	str_len = 0;
	while (s[str_len])
		str_len++;
	real_len = 0;
	if (start < str_len)
	{
		while (s[start + real_len] && real_len < len)
			real_len++;
	}
	str = (char *)malloc((real_len + 1) * sizeof(char));
	if (!(str))
		return (0);
	i = 0;
	while (i < real_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
