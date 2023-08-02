/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_previous.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:19:11 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 22:09:12 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_list_previous(List *plist, Data *pdata)
{
	if (plist->cur->prev == plist->head)
	{
		plist->cur = 0;
		*pdata = 0;
		return (FALSE);
	}
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return (TRUE);
}
