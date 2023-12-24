/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:30:41 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 15:15:22 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "minishell.h"

void	parse(t_argv **argvs);
int		add_input_to_line(t_parse *info);
int		add_line_to_token_list(t_list **token_list, t_list **dummy_list, \
			char *line);
int		create_dummy_list(t_list **dummy_list, char *line);
void	create_token_list(t_list **token_list, t_list *dummy_list);
void	create_argvs(t_argv **argvs, t_list *token_list, t_cmd **cmd, \
		t_type **type);
void	add_argv(t_argv **argvs, t_token *token, t_cmd *cmd, t_type *type);
void	add_cmd_to_argvs(t_cmd *cmd, t_argv **argvs);
void	update_env(char **line, char *input);

#endif