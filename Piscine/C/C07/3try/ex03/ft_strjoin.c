/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:55:23 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/25 11:28:21 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *str, char *result, int *point)
{
	int	i;

	i = 0;
	while (str[i])
		result[(*point)++] = str[i++];
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;
	int		i;
	int		point;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i++ != size - 1)
			total_len += ft_strlen(sep);
	}
	result = (char *)malloc((total_len + 1) * sizeof(char));
	i = 0;
	point = 0;
	while (i < size)
	{
		ft_strcpy(strs[i], result, &point);
		if (i != size - 1)
			ft_strcpy(sep, result, &point);
		i++;
	}
	result[point] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char *a[5] = {"abcd", "agjk", "gkdn", "  f1", "sd5d"};
	char *b = ",/,/";

	printf("%s\n", ft_strjoin(5, a, b));
}
*/
