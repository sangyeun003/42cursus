/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:16:59 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/29 19:58:19 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	sort_3(t_deque *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->head->data;
	n2 = a->head->next->data;
	n3 = a->head->next->next->data;
	if (n1 > n2 && n1 < n3)		// 2 1 3
		sa(a);
	else if (n2 < n1 && n2 > n3)	// 3 2 1
	{
		sa(a);
		rra(a);
	}
	else if (n3 < n1 && n3 > n2)	// 3 1 2
		ra(a);
	else if (n3 > n1 && n3 < n2)	// 1 3 2
	{
		sa(a);
		ra(a);
	}
	else if (n1 < n2 && n1 > n3)	// 2 3 1
		rra(a);
}
