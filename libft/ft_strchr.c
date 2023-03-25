/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:59:35 by sangyepa          #+#    #+#             */
/*   Updated: 2023/03/26 01:36:12 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	find = c;
	i = 0;
	while (s[i])
	{
		if ((char)s[i] == find)
			return ((char *)&s[i]);
		i++;
	}
	if (find == 0)
		return ((char *)&s[i]);
	return (0);
}
