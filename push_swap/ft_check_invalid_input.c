/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_invalid_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:22:40 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/22 21:43:59 by sangyepa         ###   ########.fr       */
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
			// 숫자 바로 뒤에 이상한 "null, space, tab, 숫자"가 아닌 다른 문자가 오면 오류
			if ((argv[i][j] >= '0' && argv[i][j] <= '9')
							&& !(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
							&& argv[i][j + 1] != ' '
							&& argv[i][j + 1] != '\t'
							&& argv[i][j + 1])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
