/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:00:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/21 14:01:04 by sangyepa         ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	int	i;

	i = ac - 1;
	while (i >= 1)
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
		i--;
	}
}
