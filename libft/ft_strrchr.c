/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:43:31 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/26 01:43:14 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	find;

	find = c;
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((char)s[i] == find)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
