/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:41:36 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/22 15:39:45 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_prime(int n)
{
	unsigned int	i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= (unsigned int)n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	while (!check_prime(nb + i))
		i++;
	return (nb + i);
}
