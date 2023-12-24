/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:05:15 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 16:19:27 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_argv	*create_argv(void)
{
	t_argv	*argv;

	argv = (t_argv *)malloc(sizeof(t_argv));
	check_malloc_error(argv);
	argv->in = NULL;
	argv->out = NULL;
	argv->hdoc = NULL;
	argv->next = NULL;
	argv->cmd = NULL;
	return (argv);
}

void	free_argv(t_argv *argv)
{
	t_argv	*tmp;

	tmp = argv;
	while (argv)
	{
		free_redir(tmp->in);
		free_redir(tmp->out);
		free_redir(tmp->hdoc);
		free_str_list(tmp->cmd);
		tmp = argv->next;
		free(argv);
		argv = tmp;
	}
}

int	ft_argvsize(t_argv *argvs)
{
	int	len;

	len = 0;
	while (argvs)
	{
		len++;
		argvs = argvs->next;
	}
	return (len);
}

t_argv	*ft_argv_last(t_argv *argv)
{
	while (ft_argvsize(argv) > 1)
		argv = argv->next;
	return (argv);
}

void	ft_argv_add_back(t_argv **argvs, t_argv *new)
{
	if (!*argvs)
		*argvs = new;
	else
		ft_argv_last(*argvs)->next = new;
}
