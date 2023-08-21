#include	<stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n = n / 2;
	if (n == 1)
		return (1);
	return (0);
}

int	main(void)
{
	printf("%d %d %d %d\n", is_power_of_2(1024), is_power_of_2(1), is_power_of_2(0), is_power_of_2(555));
	return(0);
}
