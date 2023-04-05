/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:09:40 by sangyepa          #+#    #+#             */
/*   Updated: 2023/04/05 17:04:32 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	end;
	char	*result;

	result = 0;
	if (!s1 || !set)
		return (result);
	front = 0;
	end = ft_strlen(s1);
	while (front < end && ft_strchr(set, s1[front]))
		front++;
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	if (front > end)
		return (ft_strdup("\0"));
	result = ft_substr(s1, front, end - front);
	return (result);
}
