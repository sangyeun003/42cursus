/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_overlaping_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:59:35 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 15:06:41 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	ft_is_overlaping(t_deque *pdeq, int data)
{
	t_node	*cmp;

	cmp = pdeq->head;
	while (cmp)
	{
		if (cmp->data == data)
			ft_error();
		cmp = cmp->next;
	}
}
