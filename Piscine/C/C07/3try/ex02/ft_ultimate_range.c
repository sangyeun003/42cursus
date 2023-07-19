/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:33:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/25 11:28:04 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
		return (0);
	*range = (int *)malloc((max - min) * sizeof(int));
	if (*range == 0)
		return (-1);
	i = 0;
	while (min + i < max)
	{	
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int *a;
	int n = ft_ultimate_range(&a, -5, 5);

	while (i < n)
	{
		printf("%d\n", a[i]);
		i++;
	}
}
*/
