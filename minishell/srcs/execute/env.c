/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suacho <suacho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:12:37 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 14:13:27 by suacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_env(char **cmd)
{
	t_env	*tmp;

	tmp = g_info.env_list;
	if (cmd[1])
	{
		print_error("env", "No such file or directory", FAIL);
		return ;
	}
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
