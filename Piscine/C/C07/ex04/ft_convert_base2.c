/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:50:06 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/25 16:30:13 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s);

int	ft_atoi(char *nbr, char *base_from, int sign, int i)
{
	int	result;
	int	basefrom;
	int	j;

	result = 0;
	basefrom = ft_strlen(base_from);
	j = 0;
	while (nbr[i])
	{
		j = 0;
		while (base_from[j])
		{
			if (nbr[i] == base_from[j])
				break ;
			j++;
		}
		if (base_from[j] == 0)
			break ;
		result = result * basefrom + j;
		i++;
	}
	return (sign * result);
}

char	*ft_itoa(int result, char *final, char *base_to, int len)
{
	long	baseto;
	long	n;

	if (result == 0)
	{
		final[0] = base_to[0];
		return (final);
	}
	n = (long)result;
	if (n < 0)
	{
		n *= -1;
		final[0] = '-';
	}
	baseto = ft_strlen(base_to);
	while (n > 0)
	{
		final[len - 1] = base_to[n % baseto];
		n /= baseto;
		len--;
	}
	return (final);
}

int	count_len(int result, char *base_to)
{
	int		len;
	long	baseto;
	long	n;

	if (result == 0)
		return (1);
	len = 0;
	baseto = ft_strlen(base_to);
	n = (long)result;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= baseto;
		len++;
	}
	return (len);
}
