/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:19:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 22:08:19 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_list_first(List *plist, Data *pdata)
{
	if (plist->head->next == plist->tail)
	{
		plist->cur = 0;
		*pdata = 0;
		return (FALSE);
	}
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return (TRUE);
}
