/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:16:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/28 22:04:24 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			cnt++;
		i++;
	}
	return (cnt);
}
