#include	<unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (sign * result);
}

int	main(int argc, char **argv)
{
	int	num;
	char	*base = "0123456789abcdef";
	
	if (argc == 2)
	{
		
	}
}