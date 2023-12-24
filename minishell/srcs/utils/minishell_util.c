/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:06:08 by suacho            #+#    #+#             */
/*   Updated: 2023/12/24 16:20:49 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_str_double_join(char *str1, char *str2, char *str3)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(str1, str2);
	check_malloc_error(tmp);
	res = ft_strjoin(tmp, str3);
	free(tmp);
	check_malloc_error(res);
	return (res);
}

int	isspace_all(char *line)
{
	while (*line)
	{
		if (ft_isspace(*line) == FALSE)
			return (FALSE);
		line++;
	}
	return (TRUE);
}
