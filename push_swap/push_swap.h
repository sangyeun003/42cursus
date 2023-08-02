/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:28:03 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/02 22:28:21 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include	<unistd.h>
# include	<stdlib.h>

# include	<stdio.h>

typedef int Data;

typedef struct s_node
{
	Data			data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef t_node Node;

typedef struct s_linked_list
{
	Node	*head;
	Node	*tail;
	Node	*cur;
	int		numOfData;
} t_linked_list;

typedef t_linked_list List;

int		ft_list_init(List *plist);
int		ft_list_insert(List *plist, Data data);	// head에 노드 추가
int		ft_list_first(List *plist, Data *pdata);
int		ft_list_next(List *plist, Data *pdata);
int		ft_list_previous(List *plist, Data *pdata);
Data	ft_list_remove(List *plist);
int		ft_list_count(List *plist);

int		ft_atoi(const char *str);

int		main(int argc, char *argv[]);

#endif