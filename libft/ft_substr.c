/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:33:52 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/29 00:46:20 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (s[start + i - 1] && i <= len)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!(str))
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = 0;
	return (str);
}
