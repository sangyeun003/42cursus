#include	<stdlib.h>

char	*ft_itoa(int nbr)
{
	int		i;
	int		n;
	int		len;
	char	*result;

	if (nbr == -2147483648)
		return ("-2147483648");
	n = nbr;
	len = 0;
	if (nbr < 0)
	{
		len++;
		n *= -1;
	}
	else if (nbr == 0)
		return ("0");
	while (n)
	{
		n /= 10;
		len++;
	}
	result = (char *)malloc((len + 1) * sizeof(char));
	result[len] = 0;
	// i = 0;
	while (len-- >= 0)
	{
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa(35454564));
}
