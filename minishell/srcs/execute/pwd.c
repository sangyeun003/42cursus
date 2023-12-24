/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suacho <suacho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:09:28 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 14:09:46 by suacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_pwd(char **cmd)
{
	char	cwd[PATH_MAX];

	if (cmd[1])
	{
		print_error("pwd", "too many arguments", FAIL);
		return ;
	}
	if (!getcwd(cwd, sizeof(cwd)))
	{
		print_error("pwd", strerror(errno), FAIL);
		return ;
	}
	printf("%s\n", cwd);
}
