/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:13:27 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/15 16:29:55 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int		is_printable(char c);
char	*hexa(char *s);
void	dtoh(unsigned char c);
void	ft_putstr_non_printable(char *str);

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

char	*hexa(char *s)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		s[i] = '0' + i;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		s[i + 10] = 'a' + i;
		i++;
	}
	return (s);
}

void	dtoh(unsigned char c)
{
	int		div;
	int		mod;
	char	hex[17];

	hexa(hex);
	div = c / 16;
	mod = c % 16;
	write(1, hex + div, 1);
	write(1, hex + mod, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str))
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			dtoh(*str);
		}
		str++;
	}
}
