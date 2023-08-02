/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:37:44 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 21:51:53 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

Data	ft_list_remove(List *plist)
{
	Node	*rpos = plist->cur;
	Data	rdata = rpos->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;
	free(rpos);
	plist->numOfData--;
	return (rdata);
}
