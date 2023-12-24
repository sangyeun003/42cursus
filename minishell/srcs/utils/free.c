/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suacho <suacho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:06:02 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 16:06:03 by suacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_str_list(char **str_list)
{
	char	**list_free;

	list_free = str_list;
	if (str_list == NULL)
		return ;
	while (*str_list)
	{
		free(*str_list);
		str_list++;
	}
	free(list_free);
}

void	free_lst(void *lst)
{
	free(((t_list *)lst)->content);
	free(lst);
}

void	free_content(void *content)
{
	free(content);
}

void	free_dummy(void *dummy)
{
	free(((t_dummy *)dummy)->value);
	free(dummy);
}

void	free_token(void *token)
{
	free(((t_token *)token)->value);
	free(token);
}
