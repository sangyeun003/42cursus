/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:39:40 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/24 14:39:40 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_converted_len_diu(long long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len += 1;
		nbr *= -1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_di(int n)
{
	char		*str;
	int			i;
	long long	nbr;

	nbr = (long long) n;
	str = malloc(sizeof(char) * (ft_converted_len_diu(nbr) + 1));
	if (str == 0)
		return (0);
	i = ft_converted_len_diu(nbr);
	*(str + i) = '\0';
	if (nbr < 0)
	{
		*str = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		*str = '0';
	i--;
	while (nbr > 0)
	{
		*(str + i) = '0' + nbr % 10;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

static char	*ft_itoa_u(int n)
{
	char			*str;
	int				i;
	unsigned int	nbr;

	nbr = (unsigned int) n;
	str = malloc(sizeof(char) * (ft_converted_len_diu(nbr) + 1));
	if (str == 0)
		return (0);
	i = ft_converted_len_diu(nbr);
	*(str + i) = '\0';
	if (nbr < 0)
	{
		*str = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		*str = '0';
	i--;
	while (nbr > 0)
	{
		*(str + i) = '0' + nbr % 10;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

int	ft_spec_di(va_list ap)
{
	int		num;
	int		printed_len;
	char	*printed;

	num = va_arg(ap, int);
	printed = ft_itoa_di(num);
	if (!printed)
		return (-1);
	printed_len = ft_strlen(printed);
	if (write(1, printed, printed_len) == -1)
	{
		free(printed);
		return (-1);
	}
	free(printed);
	return (printed_len);
}

int	ft_spec_u(va_list ap)
{
	int		num;
	int		printed_len;
	char	*printed;

	num = va_arg(ap, int);
	printed = ft_itoa_u(num);
	if (!printed)
		return (-1);
	printed_len = ft_strlen(printed);
	if (write(1, printed, printed_len) == -1)
	{
		free(printed);
		return (-1);
	}
	free(printed);
	return (printed_len);
}
