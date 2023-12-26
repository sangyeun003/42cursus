/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_input_to_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:46:27 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/26 14:34:51 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_env(char *input, int *flag)
{
	if (!(*flag & DM_S_QUOTE) && *input == '\"')
		*flag ^= DM_D_QUOTE;
	if (!(*flag & DM_D_QUOTE) && *input == '\'')
		*flag ^= DM_S_QUOTE;
	if (!(*flag & DM_S_QUOTE) && *input == '$')
	{
		if (*(input + 1) == '\'' || *(input + 1) == '\"')
			return (FALSE);
		if (ft_isalpha(*(input + 1)) || *(input + 1) == '_')
			return (TRUE);
		if (!ft_isspace(*(input + 1)) && *(input + 1) != '\0')
			return (TRUE);
	}
	return (FALSE);
}

static int	get_size(char *input)
{
	int		size;
	int		flag;
	char	*env;

	size = 0;
	flag = 0;
	while (*input)
	{
		if (is_env(input, &flag) == TRUE)
		{
			env = get_env_value(input);
			check_malloc_error(env);
			size += ft_strlen(env);
			input = input + get_env_key_length(input + 1) + 1;
			free(env);
		}
		else
		{
			input++;
			size++;
		}
	}
	return (size);
}

void	update_env(char **line, char *input)
{
	char	*value;
	int		size;
	int		flag;

	flag = DM_NONE;
	size = get_size(input);
	*line = malloc(sizeof(char) * (size + 1));
	if (!(*line))
		exit_shell_by_error("malloc failed");
	ft_memset(*line, 0, size + 1);
	while (*input)
	{
		if (is_env(input, &flag))
		{
			value = get_env_value(input);
			ft_strlcat(*line, value, ft_strlen(value) + ft_strlen(*line) + 1);
			input = input + get_env_key_length(input + 1) + 1;
			free(value);
		}
		else
		{
			ft_strlcat(*line, input, ft_strlen(*line) + 2);
			input++;
		}
	}
}

int	add_input_to_line(t_parse *info)
{
	info->input = readline("minishell > ");
	if (!(info->input))
	{
		free(info->input);
		exit_shell("exit");
	}
	add_history(info->input);
	update_env(&info->line, info->input);
	free(info->input);
	if (isspace_all(info->line) == TRUE)
	{
		free(info->line);
		return (FAIL);
	}
	return (SUCCESS);
}
