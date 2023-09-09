/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:39:21 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/09 23:04:10 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	ft_error(t_deque *pdeq1, t_deque *pdeq2)
{
	ft_free_deque(pdeq1, pdeq2);
	write(0, "Error\n", 6);
	exit(-1);
}
