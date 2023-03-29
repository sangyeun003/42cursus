/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:09:40 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/29 13:27:59 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	end;
	char	*result;

	if (!ft_strlen(s1))
		return ((char *)s1);
	front = 0;
	end = ft_strlen(s1) - 1;
	while (front <= end && ft_strchr(set, s1[front]))
		front++;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	if (front > end)
		return (0);
	result = (char *)malloc((end - front + 2) * sizeof(char));
	if (result == 0)
		return (0);
	ft_strlcpy(result, &s1[front], end - front + 2);
	return (result);
}
