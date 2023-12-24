/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:39:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 14:39:08 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_index_str(char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx] != c)
	{
		if (str[idx] == '\0')
			return (-1);
		idx++;
	}
	return (idx);
}
