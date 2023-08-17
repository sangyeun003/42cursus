/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/17 20:59:34 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// i = 1;
// while (i < argc)
// {
// 	char **split_result = ft_split(argv[i], " ");
// 	int j = 0;
// 	while (j < SPLIT_LEN)
// 	{
// 		PUSH(&stack, atoi(split_result[i])); 
//			 단, atoi하는 도중에 숫자가 아닌게 나오면 무조건 ERROR
// 		j++;
// 	}
// 	i++;
// }
#include	"push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	deq;

	ft_deque_init(&deq);
	ft_parsing(argc, argv, &deq);
	while (!ft_deque_is_empty(&deq))
		printf("%d ", ft_deque_remove_first(&deq));
	return (0);
}
