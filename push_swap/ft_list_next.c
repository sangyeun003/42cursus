/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:19:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 21:48:46 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_list_next(List *plist, Data *pdata)
{
	if (plist->cur->next == plist->tail)
		return (FALSE);
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return (TRUE);
}
