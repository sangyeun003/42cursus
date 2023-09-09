/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_overlaping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:59:35 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/06 12:18:32 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// deque에 add 할 때 중복 체크
#include	"push_swap.h"

int	ft_is_overlaping(t_deque *pdeq1, t_deque *pdeq2, int data)
{
	t_node	*cmp;

	cmp = pdeq1->head;
	while (cmp)
	{
		if (cmp->data == data)
			ft_error(pdeq1, pdeq2);
		cmp = cmp->next;
	}
	if (cmp)
		free(cmp);
	return (FALSE);
}
