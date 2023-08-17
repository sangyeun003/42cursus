/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_deque.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:35:34 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/17 21:44:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_free_deque(t_deque *pdeq)
{
	while (!ft_deque_is_empty(pdeq))
		ft_deque_remove_first(pdeq);
}
