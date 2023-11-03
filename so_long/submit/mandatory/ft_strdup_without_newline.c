/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_without_newline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:14:13 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 18:37:28 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*ft_strdup_without_newline(char *str)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen((char *)str);
	if (str[len - 1] == '\n')
		len--;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
