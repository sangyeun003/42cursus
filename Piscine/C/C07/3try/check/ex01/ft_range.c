/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:26:24 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/25 11:27:43 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*num;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	num = (int *)malloc((max - min) * sizeof(int));
	while (min + i < max)
	{
		num[i] = min + i;
		i++;
	}
	return (num);
}
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int *a = ft_range(-5, 5);

	while (i < 10)
	{
		printf("%d\n", a[i]);
		i++;
	}
}
*/
