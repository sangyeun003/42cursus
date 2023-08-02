/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:28:03 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 21:48:15 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include	<unistd.h>
# include	<stdlib.h>

# include	<stdio.h>

typedef int Data;

typedef struct _node
{
	Data			data;
	struct _node	*next;
	struct _node	*prev;
}	Node;

typedef struct _LinkedList
{
	Node	*head;
	Node	*tail;
	Node	*cur;
	int		numOfData;
} LinkedList;

typedef LinkedList List;

void	ft_list_init(List *plist);
void	ft_list_insert(List *plist, Data data);	// head에 노드 추가
int		ft_list_first(List *plist, Data *pdata);
int		ft_list_next(List *plist, Data *pdata);
int		ft_list_previous(List *plist, Data *pdata);
Data	ft_list_remove(List *plist);
int		ft_list_count(List *plist);

int		main(int argc, char *argv[]);

#endif