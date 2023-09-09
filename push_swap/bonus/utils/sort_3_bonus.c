/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:16:59 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 22:37:24 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	sort_3(t_deque *a, t_deque *b)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->head->data;
	n2 = a->head->next->data;
	n3 = a->head->next->next->data;
	if (n1 > n2 && n1 < n3)
		sa(a);
	else if (n2 < n1 && n2 > n3)
	{
		sa(a);
		rra(a, b);
	}
	else if (n3 < n1 && n3 > n2)
		ra(a, b);
	else if (n3 > n1 && n3 < n2)
	{
		sa(a);
		ra(a, b);
	}
	else if (n1 < n2 && n1 > n3)
		rra(a, b);
}
