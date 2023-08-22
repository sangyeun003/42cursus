/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:41:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/17 21:40:58 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"push_swap.h"

void	ft_parsing(int argc, char **argv, t_deque *pdeq)
{
	int		i;
	int		j;
	char	**split_result;

	if (!ft_check_invalid_input(argc, argv))	// space, tab, 숫자 이외의 것 확인
		ft_error(pdeq);
	i = 1;
	while (i < argc)
	{
		split_result = ft_split(argv[i], " 	");	// space, tab 구분자
		if (!split_result)
			ft_error(pdeq);
		j = 0;
		while (split_result[j])
		{
			ft_deque_add_last(pdeq, ft_atoi(split_result[j], pdeq));
			j++;
		}
		i++;
	}
}