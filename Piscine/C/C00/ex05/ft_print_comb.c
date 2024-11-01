/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:38:27 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/16 14:50:31 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char	s[3];

	s[0] = '0';
	while (s[0] <= '7')
	{
		s[1] = s[0] + 1;
		while (s[1] <= '8')
		{
			s[2] = s[1] + 1;
			while (s[2] <= '9')
			{
				write(1, s, 3);
				if (s[0] == '7' && s[1] == '8' && s[2] == '9' )
					break ;
				else
					write(1, ", ", 2);
				s[2]++;
			}
			s[1]++;
		}
		s[0]++;
	}
}
