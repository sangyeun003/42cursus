/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:39:21 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/01 16:34:05 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_error(t_deque *pdeq1, t_deque *pdeq2)
{
	ft_free_deque(pdeq1, pdeq2);
	write(1, "Error\n", 6);
	exit(-1);
}
