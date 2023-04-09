/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:28:35 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/09 16:49:25 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		del(temp->content);
		*lst = (*lst)->next;
		free(temp);
	}
}
