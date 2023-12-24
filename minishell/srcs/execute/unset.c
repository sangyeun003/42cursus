/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suacho <suacho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:10:06 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 14:25:02 by suacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	del_env_one(t_env *del)
{
	if (del->prev)
		del->prev->next = del->next;
	else
		g_info.env_list = del->next;
	if (del->next)
		del->next->prev = del->prev;
	free(del->key);
	free(del->value);
	free(del);
}

void	exec_unset(char **cmd)
{
	t_env	*del;
	int		idx;

	idx = 1;
	if (!cmd[1])
		return ;
	while (cmd[idx])
	{
		del = get_env(cmd[idx]);
		if (del)
			del_env_one(del);
		idx++;
	}
	reset_envp();
}
