/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_overlaping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:59:35 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/17 22:06:33 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// deque에 add 할 때 중복 체크
#include	"push_swap.h"

int	ft_is_overlaping(t_deque *pdeq, int data)
{
	t_node	*cmp;

	cmp = pdeq->head;
	while (cmp)
	{
		if (cmp->data == data)
			ft_error(pdeq);
		cmp = cmp->next;
	}
	return (FALSE);
}
