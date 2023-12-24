/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suacho <suacho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:39:24 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 14:18:05 by suacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	end_execute(pid_t *pids, int **pipes, t_argv *argv)
{
	free(pids);
	free_pipes(pipes);
	unlink_hdoc(argv);
	free_argv(argv);
}

static int	init_execute(int *cnt_pipe, pid_t **pids, int ***pipes, \
t_argv *argv)
{
	*pids = NULL;
	*pipes = NULL;
	set_cnt_pipe(cnt_pipe, argv);
	*pids = (pid_t *)malloc(sizeof(pid_t) * (*cnt_pipe + 1));
	if (!(*pids))
		exit_shell_by_error("malloc failed");
	if (*cnt_pipe > 0)
	{
		if (set_pipes(pipes, *cnt_pipe) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

void	execute(t_argv *argv)
{
	pid_t	*pids;
	int		**pipes;
	int		cnt_pipe;

	if (check_hdoc(argv) == FAIL)
		return (free_argv(argv));
	set_echoctl();
	if (init_execute(&cnt_pipe, &pids, &pipes, argv) == FAIL)
	{
		g_info.last_exit_status = FAIL;
		return (end_execute(pids, pipes, argv));
	}
	if (cnt_pipe == 0 && is_builtin(argv->cmd) == TRUE)
		run_single_process(argv);
	else
		run_multi_process(argv, pids, pipes, cnt_pipe);
	end_execute(pids, pipes, argv);
}
