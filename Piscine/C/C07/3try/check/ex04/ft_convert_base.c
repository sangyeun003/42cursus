/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:49:32 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/25 16:30:57 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int		ft_atoi(char *nbr, char *base_from, int sign, int i);
char	*ft_itoa(int result, char *final, char *base_to, int len);
int		count_len(int result, char *base_to);

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	base_check(char *s)
{
	int	i;
	int	j;

	if (ft_strlen(s) < 2)
		return (0);
	i = 0;
	while (s[i])
	{
		j = i + 1;
		if (s[i] == '-' || s[i] == '+')
			return (0);
		else if ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
			return (0);
		while (s[j])
		{
			if (s[i] == s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	space_sign_check(char *nbr, int *i, int *sign)
{
	while ((nbr[*i] >= 9 && nbr[*i] <= 13) || nbr[*i] == 32)
		(*i)++;
	while (nbr[*i] == '-' || nbr[*i] == '+')
	{
		if (nbr[*i] == '-')
			(*sign) *= (-1);
		(*i)++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		i;
	int		result;
	int		len;
	char	*final;

	sign = 1;
	i = 0;
	result = 0;
	if (!(base_check(base_from)) || !(base_check(base_to)))
		return (0);
	space_sign_check(nbr, &i, &sign);
	result = ft_atoi(nbr, base_from, sign, i);
	len = count_len(result, base_to);
	final = (char *)malloc((len + 1) * sizeof(char));
	ft_itoa(result, final, base_to, len);
	final[len] = '\0';
	return (final);
}
/*
#include <stdio.h>
int main()
{
	char *basefrom = "i~pv";
	char *baseto = "gYhQ_zUVuv";

	printf("%s\n", ft_convert_base("i", basefrom, baseto));
	printf("%s\n", ft_convert_base("+-+- 20000", basefrom, baseto));
	printf("%s\n", ft_convert_base(" ++-+-+-20000", basefrom, baseto));

}
*/
