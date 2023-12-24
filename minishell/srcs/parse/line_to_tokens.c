/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:07:01 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 14:28:30 by sangyepa         ###   ########.fr       */
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

static int	is_valid_syntax(t_list	*tokens)
{
	t_token	*token;
	int		last_type;

	last_type = TK_NONE;
	while (tokens)
	{
		token = (t_token *)tokens->content;
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
		tokens = tokens->next;
	}
	if (last_type != TK_WORD)
		return (FALSE);
	return (TRUE);
}

int	line_to_tokens(t_list **tokens, t_list **dummies, char *line)
{
	if (create_dummies(dummies, line) == FAIL)
		return (ERROR_DUMMIES);
	create_tokens(tokens, *dummies);
	ft_lstclear(dummies, free_dummy);
	if (is_valid_syntax(*tokens) == FALSE)
		return (ERROR_SYNTAX);
	return (ERROR_NO_OCCURED);
}
