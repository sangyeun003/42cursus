/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:59 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 22:47:34 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	pa(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(b, a);
	ft_deque_add_first(a, b, data);
}

void	pb(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(a, b);
	ft_deque_add_first(b, a, data);
}
