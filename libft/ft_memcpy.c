/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:34:12 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/09 19:31:20 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst == 0 && src == 0)
		return (0);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (t_dst[i] != t_src[i])
			t_dst[i] = t_src[i];
		i++;
	}
	return (dst);
}
