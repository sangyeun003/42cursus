/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:33:03 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/29 14:06:40 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	len(int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (n < 0)
	{
		count++;
		num = (unsigned int)n * -1;
	}
	else if (n > 0)
		num = n;
	else
		return (1);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	num;

	size = len(n);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!(result))
		return (0);
	num = n;
	if (num < 0)
	{
		result[0] = '-';
		num = num * -1;
	}
	result[size] = 0;
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[--size] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}
