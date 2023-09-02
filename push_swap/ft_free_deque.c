/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_deque.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:35:34 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/01 17:14:07 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_free_deque(t_deque *pdeq1, t_deque *pdeq2)
{
	while (!ft_deque_is_empty(pdeq1))
		ft_deque_remove_first(pdeq1);
	while (!ft_deque_is_empty(pdeq2))
		ft_deque_remove_first(pdeq2);
	// free(pdeq1);
	// free(pdeq2);
}
