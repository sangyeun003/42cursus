/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_invalid_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:22:40 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 19:59:00 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	is_number(int i, int j, char **argv)
{
	if (argv[i][j] != ' ' && argv[i][j] != '	' && argv[i][j] != '+'
							&& argv[i][j] != '-' && !ft_isdigit(argv[i][j]))
		return (FALSE);
	if ((argv[i][j] >= '0' && argv[i][j] <= '9')
					&& !(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
					&& argv[i][j + 1] != ' '
					&& argv[i][j + 1] != '\t'
					&& argv[i][j + 1])
		return (FALSE);
	return (TRUE);
}

int	ft_check_invalid_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				break ;
			j++;
		}
		if (argv[i][j] == 0)
			return (FALSE);
		j = 0;
		while (argv[i][j])
		{
			if (!is_number(i, j, argv))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
