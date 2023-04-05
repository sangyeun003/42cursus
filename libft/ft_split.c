/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:07:10 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/05 17:15:54 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	numofword(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	count_word_len(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	alloc_word(char **result, char const *s, char c, int num_of_word)
{
	int	i;
	int	wordlen;

	i = -1;
	while (++i < num_of_word)
	{
		while (*s == c)
			s++;
		wordlen = count_word_len(s, c);
		result[i] = (char *)malloc((wordlen + 1) * sizeof(char));
		if (result[i] == 0)
		{
			while (--i >= 0)
				free(result[i]);
			free(result);
			return (0);
		}
		ft_strlcpy(result[i], s, wordlen + 1);
		while (*s && *s != c)
			s++;
	}
	result[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_of_word;

	num_of_word = numofword(s, c);
	result = (char **)malloc((num_of_word + 1) * sizeof(char *));
	if (result == 0)
		return (0);
	if (!alloc_word(result, s, c, num_of_word))
		return (0);
	return (result);
}
