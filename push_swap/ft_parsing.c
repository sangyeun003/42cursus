/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:41:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/17 21:00:46 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 의사 코드
// ex) ./push_swap "1 2 3" 4 5 "6"
// argc = 5
// argv = ["1 2 3", "4", "5", "6"]
// split 후 -> ['1', '2', '3'], ['4'], ['5'], ['6']
// atoi 후  -> 1, 2, 3, 4, 5, 6를 stack에 저장

// i = 1;
// while (i < argc)
// {
// 	char **split_result = ft_split(argv[i], " ");
// 	int j = 0;
// 	while (split_result[j])
// 	{
// 		PUSH(&stack, atoi(split_result[i])); // 단, atoi하는 도중에 숫자가 아닌게 나오면 무조건 ERROR
// 		j++;
// 	}
// 	i++;
// }
#include	"push_swap.h"

void	ft_parsing(int argc, char **argv, t_deque *pdeq)
{
	int		i;
	int		j;
	char	**split_result;

	i = 1;
	while (i < argc)
	{
		split_result = ft_split(argv[i], " 	");	// space, tab 구분자
		j = 0;
		while (split_result[j])
		{
			ft_deque_add_last(pdeq, ft_atoi(split_result[j]));
			j++;
		}
		i++;
	}
}
