/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:32:39 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/27 14:43:16 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	check_in_sep(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	num_of_word(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && check_in_sep(str[i], charset))
			i++;
		if (str[i] && !check_in_sep(str[i], charset))
			size++;
		while (str[i] && !check_in_sep(str[i], charset))
			i++;
	}
	return (size);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str && check_in_sep(*str, charset))
		str++;
	while (*(str + len) && !check_in_sep(*(str + len), charset))
		len++;
	return (len);
}

void	alloc_word(char **result, char *str, char *charset, int size)
{
	int	i;
	int	j;
	int	wordlen;

	i = 0;
	j = 0;
	while (i < size)
	{
		wordlen = word_len(str, charset);
		result[i] = (char *)malloc((wordlen + 1) * sizeof(char));
		while (*str && check_in_sep(*str, charset))
			str++;
		while (j < wordlen)
		{
			result[i][j] = *(str++);
			j++;
		}
		result[i][j] = '\0';
		j = 0;
		i++;
	}
	result[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		size;
	int		i;

	i = 0;
	size = num_of_word(str, charset);
	result = (char **)malloc((size + 1) * sizeof(char *));
	alloc_word(result, str, charset, size);
	return (result);
}
