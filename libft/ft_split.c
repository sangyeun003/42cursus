/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:07:10 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/29 14:15:58 by sangyepa         ###   ########.fr       */
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
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_of_word;
	int		wordlen;
	int		i;

	num_of_word = numofword(s, c);
	result = (char **)malloc(num_of_word * sizeof(char *));
	if (result == 0)
		return (0);
	i = 0;
	while (i < num_of_word)
	{
		result[i] = (char *)malloc(wordlen * sizeof(char));
		if (result[i] == 0)
		{
			while (--i >= 0)
				free(result[i]);
			free(result);
			return (0);
		}
		
	}
}
