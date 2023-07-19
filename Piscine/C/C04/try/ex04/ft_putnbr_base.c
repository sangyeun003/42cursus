/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:26:01 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/19 18:38:47 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_num_based(int nbr, unsigned int b, char *base)
{
	unsigned int	n;

	if (nbr < 0)
	{
		if (nbr != -2147483648)
			n = nbr * (-1);
		else
			n = 2147483648;
	}
	else
		n = nbr;
	if (n < b)
	{
		write(1, &base[n], 1);
		return ;
	}
	ft_print_num_based(n / b, b, base);
	ft_print_num_based(n % b, b, base);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;

	b = ft_strlen(base);
	if (check(base) && b != 0 && b != 1)
	{
		if (nbr < 0)
			write(1, "-", 1);
		ft_print_num_based(nbr, b, base);
	}
}
