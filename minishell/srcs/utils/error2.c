/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suacho <suacho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:05:54 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 16:05:55 by suacho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_error(char *cmd, char *msg, int err_num)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	g_info.last_exit_status = err_num;
}

void	print_error_exit(char *cmd, char *msg, int exit_num)
{
	print_error(cmd, msg, exit_num);
	exit(exit_num);
}
