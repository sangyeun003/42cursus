/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:29:18 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 14:29:24 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_env_list(void)
{
	t_env	*env_list;
	t_env	*target;

	env_list = g_info.env_list;
	if (!env_list)
		return ;
	while (env_list)
	{
		target = env_list;
		env_list = env_list->next;
		free(target->key);
		free(target->value);
		free(target);
	}
	g_info.env_list = 0;
}

t_env	*get_env(char *key)
{
	t_env	*env_list;

	env_list = g_info.env_list;
	while (env_list)
	{
		if (ft_strcmp(env_list->key, key) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

t_env	*make_env(char *env_str)
{
	t_env	*new_env;
	int		seperator_idx;
	char	*value;

	new_env = (t_env *)malloc(sizeof(t_env));
	check_malloc_error(new_env);
	seperator_idx = ft_index_str(env_str, '=');
	new_env->key = ft_strndup(env_str, seperator_idx);
	value = env_str + seperator_idx + 1;
	if (ft_strcmp(new_env->key, "SHLVL") == 0)
		new_env->value = ft_strdup(ft_itoa(ft_atoi(value) + 1));
	else
		new_env->value = ft_strdup(env_str + seperator_idx + 1);
	new_env->next = NULL;
	new_env->prev = NULL;
	return (new_env);
}

void	add_env(t_env **lst, char *env_str)
{
	t_env	*new_env;
	t_env	*tmp;

	tmp = *lst;
	new_env = make_env(env_str);
	check_malloc_error(new_env);
	if (!(*lst))
		(*lst) = new_env;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		new_env->prev = *lst;
		(*lst)->next = new_env;
		(*lst) = (*lst)->next;
	}
	while ((*lst)->prev)
		(*lst) = (*lst)->prev;
}

void	init_env(char **envp)
{
	t_env	*env_list;

	env_list = NULL;
	while (*envp)
	{
		add_env(&env_list, *envp);
		envp++;
	}
	g_info.env_list = env_list;
}
