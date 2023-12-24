/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:39:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 14:39:55 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int len)
{
	char	*string;
	int		idx;

	string = (char *)malloc(len + 1);
	if (!string)
		return (FT_NULL);
	idx = 0;
	while (src[idx] && idx < len)
	{
		string[idx] = src[idx];
		idx++;
	}
	string[idx] = '\0';
	return (string);
}
