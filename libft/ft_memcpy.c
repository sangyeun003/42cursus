/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:34:12 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/20 20:02:08 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (t_dst[i] != t_src[i])
			t_dst[i] = t_src[i];
		i++;
	}
	return (t_dst);
}
