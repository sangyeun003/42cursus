/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:09:33 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/18 20:21:46 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (*to_find == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = i + 1;
			k = 1;
			while (str[j] && to_find[k] && str[j] == to_find[k])
			{
				j++;
				k++;
			}
			if (to_find[k] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
