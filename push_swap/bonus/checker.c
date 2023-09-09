/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:30:32 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/03 21:36:54 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;
	char	*cmd;

	if (argc < 2)
		return (0);
	ft_deque_init(&a);
	ft_deque_init(&b);
	ft_parsing(argc, argv, &a, &b);
	while (1)
	{
		
	}
	return (0);
}