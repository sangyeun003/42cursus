/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:05:20 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/09 16:33:34 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	c;

	c = 48;
	while (c < 58)
	{
		write(1, &c, 1);
		c++;
	}
	return ;
}
