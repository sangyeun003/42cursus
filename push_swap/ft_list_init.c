/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:19:02 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 22:36:31 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_list_init(List *plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	if (plist->head == 0)
		return (FALSE);
	plist->head->data = 0;
	plist->head->prev = 0;
	plist->head->next = plist->tail;
	plist->tail = (Node *)malloc(sizeof(Node));
	if (plist->tail == 0)
		return (FALSE);
	plist->tail->data = 0;
	plist->tail->prev = plist->head;
	plist->tail->next = 0;
	plist->cur = 0;
	plist->numOfData = 0;
	return (TRUE);
}
