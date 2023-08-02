/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:27:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 22:47:32 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char *argv[])
{
	List	stack_a;
	List	stack_b;
	Data	data;
	int		i;
	char	*command;

	if (!ft_list_init(&stack_a) || !ft_list_init(&stack_b))
	{
		printf("Error\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_list_insert(&stack_a, ft_atoi(argv[i++])))
		{
			printf("Error\n");
			return (0);
		}
	}
	if (!ft_list_first(&stack_a, &data))
	{
		printf("Error\n");
		return (0);
	}
	printf("%d ", data);
	while (ft_list_next(&stack_a, &data))
		printf("%d ", data);
	
	return (0);
}
