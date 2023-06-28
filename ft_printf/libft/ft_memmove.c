/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:17:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/09 19:31:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (dst == 0 && src == 0)
		return (0);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (t_dst < t_src)
	{
		i = 0;
		while (i < n)
		{
			t_dst[i] = t_src[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			t_dst[n] = t_src[n];
	}
	return (dst);
}
