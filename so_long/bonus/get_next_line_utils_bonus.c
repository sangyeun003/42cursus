/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:33 by sangyepa          #+#    #+#             */
/*   Updated: 2023/10/02 17:22:40 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

int	ft_refine_backup(char **backup, char **line)
{
	char	*temp;

	if (ft_strchr(*backup, '\n'))
	{
		temp = ft_strdup(ft_strchr(*backup, '\n') + 1);
		if (!temp)
		{
			ft_free_two_str(backup, line);
			return (0);
		}
		free(*backup);
		*backup = ft_strdup(temp);
		free(temp);
		if (!*backup)
		{
			ft_free_two_str(line, line);
			return (0);
		}
	}
	else
		ft_free_two_str(backup, backup);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	find = (char)c;
	i = 0;
	while (s[i])
	{
		if ((char)s[i] == find)
			return ((char *)&s[i]);
		i++;
	}
	if (find == 0)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen((char *)s1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
