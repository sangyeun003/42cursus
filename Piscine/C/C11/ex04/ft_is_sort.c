/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:19:32 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/28 19:42:58 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	increasing;
	int	decreasing;

	i = 0;
	increasing = 0;
	decreasing = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			increasing++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			decreasing++;
		i++;
	}
	if (increasing == length - 1 || decreasing == length - 1 || length == 0)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	check_sort(int a, int b)
{
	if (a - b)
		return (a - b);
	return (0);
}

int main(void)
{
	int tab1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	tab2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int	tab3[10] = {0, -1, -2, -3, -4, -5, -6, -7, -8, -9};
	int	tab4[10] = {1, 3, 2, 4, -2, 5, 3, 9, 10, 0};
	int	tab5[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -5};
	int	tab6[10] = {-5, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	tab7[10] = {0, -1, -2, -3, -4, -5, -6, -7, -8, 10};
	int	tab8[0];

	printf("-- test 1 --\n");
	printf("Expected : 1, uesr_output: %d\n", ft_is_sort(tab1, 10, check_sort));
	printf("-- test 2 --\n");
	printf("Expected : 1, uesr_output: %d\n", ft_is_sort(tab2, 10, check_sort));
	printf("-- test 3 --\n");
	printf("Expected : 1, uesr_output: %d\n", ft_is_sort(tab3, 10, check_sort));
	printf("-- test 4 --\n");
	printf("Expected : 0, user_output: %d\n", ft_is_sort(tab4, 10, check_sort));
	printf("-- test 5 --\n");
	printf("Expected : 0, user_output: %d\n", ft_is_sort(tab5, 10, check_sort));
	printf("-- test 6 --\n");
	printf("Expected : 1, user_output: %d\n", ft_is_sort(tab6, 10, check_sort));
	printf("-- test 7 --\n");
	printf("Expected : 0, user_output: %d\n", ft_is_sort(tab7, 10, check_sort));
	printf("-- test 8 --\n");
	printf("Expected : 0, user_output: %d\n", ft_is_sort(tab8, 0, check_sort));
}
*/
