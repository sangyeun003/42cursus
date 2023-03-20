/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:55:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/20 20:05:59 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*result;

	len = ft_strlen((char *)s1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
