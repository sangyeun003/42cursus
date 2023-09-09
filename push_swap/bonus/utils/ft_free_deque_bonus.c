/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_deque_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:35:34 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 23:02:51 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	ft_free_deque(t_deque *pdeq1, t_deque *pdeq2)
{
	if (!pdeq1 || !pdeq2)
		return ;
	while (!ft_deque_is_empty(pdeq1))
		ft_deque_remove_first(pdeq1, pdeq2);
	while (!ft_deque_is_empty(pdeq2))
		ft_deque_remove_first(pdeq2, pdeq1);
}
