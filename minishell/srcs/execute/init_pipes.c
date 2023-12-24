/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suacho <suacho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:49:48 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 13:50:59 by suacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_cnt_pipe(int *cnt_pipe, t_argv *argv)
{
	t_argv	*tmp;
	int		cnt;

	cnt = 0;
	if (!argv)
	{
		*cnt_pipe = 0;
		return ;
	}
	tmp = argv->next;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	*cnt_pipe = cnt;
}

int	set_pipes(int ***pipes, int cnt_pipe)
{
	int	idx;

	idx = 0;
	*pipes = (int **)malloc(sizeof(int *) * (cnt_pipe + 1));
	if (!(*pipes))
		exit_shell_by_error("malloc failed");
	(*pipes)[cnt_pipe] = NULL;
	while (idx < cnt_pipe)
	{
		(*pipes)[idx] = (int *)malloc(sizeof(int) * 2);
		idx++;
	}
	idx = 0;
	while (idx < cnt_pipe)
	{
		if (pipe((*pipes)[idx]) < 0)
		{
			print_error("pipe", strerror(errno), FAIL);
			close_pipes(*pipes, idx);
			return (FAIL);
		}
		idx++;
	}
	return (SUCCESS);
}
