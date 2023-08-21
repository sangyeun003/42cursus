#include	<stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == '-' || base[i] == '+' || base[i] == 32)
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(const char *str, char *base)
{
	int	i;
	int	n;
	int	base_len;
	int	result;
	int	sign;

	result = 0;
	if (base_check(base))
	{
		i = 0;
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else
			sign = 1;
		base_len = ft_strlen(base);
		while (str[i])
		{
			n = 0;
			while (base[n])
			{
				if (str[i] == base[n])
				{
					result = result * base_len + n;
					break ;
				}
				n++;
			}
			if (n == base_len)
				break ;
			i++;
		}
	}
	return (sign * result);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("12fdb3", "12fdb3"));
	return (0);
}
