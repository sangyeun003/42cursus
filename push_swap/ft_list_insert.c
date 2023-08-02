/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:19:06 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 22:55:40 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_list_insert(List *plist, Data data)	// stack이니까 head에 데이터 추가
{
	Node	*newnode;

	newnode = (Node *)malloc(sizeof(Node));
	if (!newnode || !data)
		return (FALSE);
	newnode->data = data;
	newnode->next = plist->head->next;
	
	plist->head->next->prev = newnode;	// 이 문장 때문에 에러나는 듯
	printf("통과\n");
	
	newnode->prev = plist->head;
	plist->head->next = newnode;
	plist->numOfData++;
	return (TRUE);
}
