/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:53:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/20 19:57:10 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
		p[i++] = (unsigned char)c;
	return (p);
}

// #include	<string.h>
// #include	<stdio.h>
// int main(void)
// {
// 	int word[6] = {1,2,3,4,5};
// 	int *temp;
// 	temp = ft_memset(word, 3, 5 * sizeof(int));
// 	for (int i = 0; i < 5; i++)
// 		printf("%d ", temp[i]);
// 	printf("\n");
// 	printf("%d", 0x03030303);
// }