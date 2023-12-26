/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:26:26 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/26 14:19:14 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse(t_argv **argvs)
{
	t_parse	info;
	int		error;

	while (TRUE)
	{
		ft_memset(&info, 0, sizeof(t_parse));
		if (add_input_to_line(&info) == FAIL)
		{
			ft_lstclear(&info.dummys, free_dummy);
			continue ;
		}
		error = add_line_to_token_list(&info.tokens, &info.dummys, info.line);
		free(info.line);
		ft_lstclear(&info.dummys, free_dummy);
		if (error & ERROR_OCCURED)
		{
			check_token_error(info, error);
			continue ;
		}
		create_argvs(argvs, info.tokens, &info.cmd, &info.type);
		if (error == ERROR_NO_OCCURED)
			break ;
	}
}
