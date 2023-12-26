/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:19:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/26 14:19:41 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_token_error(t_parse info, int error)
{
	if (error & ERROR_DUMMIES)
		return (error);
	if (error & ERROR_SYNTAX)
		shell_error("syntax error: unexpected tokens", EXIT_STATUS_FAILURE);
	if (error & ERROR_OCCURED)
		ft_lstclear(&info.tokens, free_token);
	return (error);
}