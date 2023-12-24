/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_to_token_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:07:01 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 15:15:53 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_redir_type(char *value)
{
	if (ft_strcmp(value, ">") == 0)
		return (RD_T_OUT);
	else if (ft_strcmp(value, ">>") == 0)
		return (RD_A_OUT);
	else if (ft_strcmp(value, "<") == 0)
		return (RD_IN);
	else if (ft_strcmp(value, "<<") == 0)
		return (RD_HDOC);
	return (RD_NONE);
}

static int	is_valid_syntax(t_list	*token_list)
{
	t_token	*token;
	int		last_type;

	last_type = TK_NONE;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (last_type == TK_NONE && token->type == TK_PIPE)
			return (FALSE);
		if (last_type == TK_REDIR && token->type != TK_WORD)
			return (FALSE);
		if (last_type == TK_PIPE && token->type == TK_PIPE)
			return (FALSE);
		if (token->type == TK_REDIR && \
			check_redir_type(token->value) == RD_NONE)
			return (FALSE);
		last_type = token->type;
		token_list = token_list->next;
	}
	if (last_type != TK_WORD)
		return (FALSE);
	return (TRUE);
}

int	add_line_to_token_list(t_list **token_list, t_list **dummy_list, char *line)
{
	if (create_dummy_list(dummy_list, line) == FAIL)
		return (ERROR_DUMMIES);
	create_token_list(token_list, *dummy_list);
	ft_lstclear(dummy_list, free_dummy);
	if (is_valid_syntax(*token_list) == FALSE)
		return (ERROR_SYNTAX);
	return (ERROR_NO_OCCURED);
}
