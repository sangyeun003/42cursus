/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:22:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/09 20:24:10 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	char	*result;
	size_t	len;
	size_t	i;

	tmp = (char *)s;
	len = ft_strlen((char *)s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = f((unsigned int)i, tmp[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
