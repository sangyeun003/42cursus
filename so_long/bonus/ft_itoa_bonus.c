/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:43:16 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/03 17:29:10 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	num_len(int n)
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

	size = num_len(n);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!(result))
		print_error("Malloc failed!");
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

char	*step_char(char *step)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(step) + 7;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		print_error("Malloc failed!");
	result[0] = 'S';
	result[1] = 't';
	result[2] = 'e';
	result[3] = 'p';
	result[4] = 's';
	result[5] = ':';
	result[6] = ' ';
	i = 7;
	while (i < len)
	{
		result[i] = step[i - 7];
		i++;
	}
	result[i] = 0;
	return (result);
}
