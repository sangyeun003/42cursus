/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:09:40 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/29 12:39:16 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	end;
	char	*result;

	front = 0;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	end = ft_strlen(s1);
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	if (front <= end)
	{
		result = (char *)malloc((end - front + 1) * sizeof(char));
		if (result == 0)
			return (0);
		ft_strlcpy(result, &s1[front], end - front + 2);
	}
	else
	{
		result = (char *)malloc(sizeof(char));
		result[0] = 0;
	}
	return (result);
}
