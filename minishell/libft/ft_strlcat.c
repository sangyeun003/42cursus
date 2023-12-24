/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:11:47 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/09 20:22:42 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = (unsigned int)ft_strlen(dest);
	i = 0;
	if (size >= len + 1)
	{
		while (i < size - len - 1 && src[i])
		{
			dest[len + i] = src[i];
			i++;
		}
		dest[len + i] = '\0';
		return (len + (unsigned int)ft_strlen(src));
	}
	else
		return (size + (unsigned int)ft_strlen(src));
}
