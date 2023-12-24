/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:49:27 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 16:23:35 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "minishell.h"

void	init_env(char **env);
t_env	*make_env(char *env_line);
void	add_env(t_env **lst, char *env_line);
t_env	*get_env(char *key);
char	*get_env_value(char *line);
int		get_env_key_length(char *str);
void	free_env_list(void);

void	exit_shell(char *str);
void	exit_shell_by_error(char *str);
void	check_malloc_error(void *target);
void	shell_error(char *str, int exit_status);
void	print_error(char *cmd, char *msg, int err_num);
void	print_error_exit(char *cmd, char *msg, int exit_num);

void	unset_echoctl(void);
void	set_echoctl(void);

void	register_signal_handler(void);
void	ignore_signal(void);
void	default_signal(void);

int		isspace_all(char *line);

char	*ft_str_double_join(char *str1, char *str2, char *str3);

void	free_str_list(char **str_list);
void	free_content(void *content);
void	free_dummy(void *dummy);
void	free_token(void *token);
void	free_lst(void *lst);
void	free_env(void *env);
void	free_redir(t_redir *redir);

int		ft_redirsize(t_redir *redirs);
t_redir	*ft_redir_last(t_redir *redir);
void	ft_redir_add_back(t_redir **redirs, t_redir *new);
void	free_argv(t_argv *argv);
int		ft_argvsize(t_argv *argvs);
t_argv	*ft_argv_last(t_argv *argv);
void	ft_argv_add_back(t_argv **argvs, t_argv *new);
t_argv	*create_argv(void);
int		check_redir_type(char *value);
t_redir	*create_redir(void);
void	hdoc_sigint_handler(int signo);
void	reset_envp(void);

#endif