/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:59 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 15:09:26 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	pa(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(b);
	ft_deque_add_first(a, data);
}

void	pb(t_deque *a, t_deque *b)
{
	int	data;

	data = ft_deque_remove_first(a);
	ft_deque_add_first(b, data);
}
