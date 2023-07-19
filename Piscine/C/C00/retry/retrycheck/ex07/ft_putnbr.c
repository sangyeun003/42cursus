/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:51:14 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/16 15:44:56 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putnbr(int nb);
char	*ft_strrev(char *s);
int		ft_strlen(char *s);
void	ft_reset(char *s);

void	ft_reset(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	n[11];
	int		i;

	i = 0;
	ft_reset(n);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
	}
	while (i < 10)
	{
		n[i] = nb % 10 + '0';
		nb = nb / 10;
		if (nb == 0)
			break ;
		i++;
	}
	ft_strrev(n);
	write(1, n, ft_strlen(n));
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}
