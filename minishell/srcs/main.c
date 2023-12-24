/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:30:21 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 15:25:47 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_info	g_info;

int	main(int argc, char **argv, char **envp)
{
	t_argv	*argvs;

	(void)argv;
	if (argc != 1)
		exit_shell_by_error("invalid argv");
	g_info.pid = getpid();
	init_env(envp);
	while (TRUE)
	{
		argvs = NULL;
		unset_echoctl();
		register_signal_handler();
		parse(&argvs);
		execute(argvs);
	}
}
