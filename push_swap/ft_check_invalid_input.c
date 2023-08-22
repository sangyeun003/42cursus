/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_invalid_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:22:40 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/22 17:36:24 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 숫자, space, tab 이외의 것이 argv에 들어있나 check
#include	"push_swap.h"

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
			if (argv[i][j] != ' ' && argv[i][j] != '	' && argv[i][j] != '+'
								&& argv[i][j] != '-' && !ft_isdigit(argv[i][j]))
				return (FALSE);
			if ((argv[i][j] == ' ' || argv[i][j] == '\t')
								&& argv[i][j + 1] == 0)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
