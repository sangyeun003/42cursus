/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:17:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/20 19:56:08 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return ((void *)t_dst);
}
