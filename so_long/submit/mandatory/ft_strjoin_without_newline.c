/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_without_newline.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:14:59 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 18:37:07 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*ft_strjoin_without_newline(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (s2[ft_strlen(s2) - 1] == '\n')
		len--;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		exit(1);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len)
		result[i++] = s2[j++];
	result[i] = 0;
	return (result);
}