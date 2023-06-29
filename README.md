# 42Seoul
1. Libft
2. ft_printf

void	ft_putp(void *address, int *result)
{
	unsigned int	num;
	char			*temp;

	num = 0;
	temp = (char *)address;
	while (*temp)
	{
		if (*temp >= '0' && *temp <= '9')
			num = num * 16 + *temp - '0';
		else
			num = num * 16 + *temp - 'a' + 10;
		temp++;
	}
	ft_putunsignedint_hex_small(num, result);
}

