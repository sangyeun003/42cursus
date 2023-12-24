/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:00:37 by dohyunki          #+#    #+#             */
/*   Updated: 2023/12/24 16:23:25 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

void		execute(t_argv *argv);
void		set_cnt_pipe(int *cnt_pipe, t_argv *argv);
int			set_pipes(int ***pipes, int cnt_pipe);
void		close_pipes(int **pipes, int cnt);
void		free_pipes(int **pipes);
int			is_builtin(char **cmd);
void		run_single_process(t_argv *argv);
int			set_stdin_redir(t_argv *argv);
int			set_stdout_redir(t_argv *argv);
void		set_stdin_pipe(int **pipes, int num);
void		set_stdout_pipe(t_argv *argv, int **pipes, int num);
void		reset_stdin(int fd);
void		reset_stdout(int fd);
void		run_builtin_process(char **cmd);
void		exec_echo(char **cmd);
void		exec_cd(char **cmd);
void		exec_pwd(char **cmd);
void		exec_export(char **cmd);
int			is_valid_key(char *key);
void		exec_unset(char **cmd);
void		exec_env(char **cmd);
void		exec_exit(char **cmd);
char		*get_path(char *cmd);
void		run_multi_process(t_argv *argv, pid_t *pids, int **pipes, \
			int cnt_pipe);
int			ft_open(char *file, int type);
void		unlink_hdoc(t_argv *argv);
int			check_hdoc(t_argv *argv);

#endif