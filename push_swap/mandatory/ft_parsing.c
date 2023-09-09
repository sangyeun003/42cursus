/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:41:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 21:08:28 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_parsing(int argc, char **argv, t_deque *pdeq1, t_deque *pdeq2)
{
	int		i;
	int		j;
	char	**split_result;

	if (!ft_check_invalid_input(argc, argv))
		ft_error(pdeq1, pdeq2);
	i = 1;
	while (i < argc)
	{
		split_result = ft_split(argv[i], " 	");
		if (!split_result)
			ft_error(pdeq1, pdeq2);
		j = 0;
		while (split_result[j])
		{
			ft_deque_add_last(pdeq1, pdeq2,
				ft_atoi(split_result[j], pdeq1, pdeq2));
			j++;
		}
		j = 0;
		while (split_result[j])
			free(split_result[j++]);
		free(split_result);
		i++;
	}
}
