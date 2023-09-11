/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 15:55:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	ra(t_deque *a)
{
	int	data;

	data = ft_deque_remove_first(a);
	ft_deque_add_last(a, data);
}

void	rb(t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(b);
	ft_deque_add_last(b, data);
}

void	rr(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(a);
	ft_deque_add_last(a, data);
	data = ft_deque_remove_first(b);
	ft_deque_add_last(b, data);
}
