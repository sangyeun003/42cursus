/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:59 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 19:54:28 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(b, a);
	ft_deque_add_first(a, b, data);
	write(1, "pa\n", 3);
}

void	pb(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(a, b);
	ft_deque_add_first(b, a, data);
	write(1, "pb\n", 3);
}
