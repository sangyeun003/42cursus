/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:29:05 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 15:16:26 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_token_type(int type)
{
	if (type & DM_REDIR)
		return (TK_REDIR);
	if (type & DM_PIPE)
		return (TK_PIPE);
	return (TK_WORD);
}

static char	*get_token_value(t_list **dummy_list)
{
	t_dummy	*dummy;
	char	*value;

	if (((t_dummy *)((*dummy_list)->content))->type & (DM_NONE | DM_SPACE))
	{
		*dummy_list = (*dummy_list)->next;
		return (NULL);
	}
	value = ft_strdup("");
	while (*dummy_list)
	{
		dummy = (*dummy_list)->content;
		if (dummy->type & (DM_NONE | DM_SPACE))
		{
			*dummy_list = (*dummy_list)->next;
			break ;
		}
		value = gnl_strjoin_and_free(value, dummy->value);
		*dummy_list = (*dummy_list)->next;
	}
	return (value);
}

static void	add_dummies_to_token_list(t_list **token_list, t_list **dummy_list)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->type = get_token_type(((t_dummy *)(*dummy_list)->content)->type);
	token->value = get_token_value(dummy_list);
	if (token->value)
		ft_lstadd_back(token_list, ft_lstnew(token));
	else
		free_token(token);
}

void	create_token_list(t_list **token_list, t_list *dummy_list)
{
	while (dummy_list)
		add_dummies_to_token_list(token_list, &dummy_list);
}
