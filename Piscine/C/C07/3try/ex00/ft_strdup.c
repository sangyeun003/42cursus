/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:25:31 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/25 11:27:26 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	while (i < len)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char *s = "aghajksddhf";
	printf("%s\n%c", ft_strdup(s), s[10]);
}
*/
