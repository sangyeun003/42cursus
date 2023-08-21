#include	<unistd.h>

void	print_bits(unsigned char octet)
{
	char	result[9];

	for (int i = 0; i < 8; i++)
	{
		result[7 - i] = octet % 2 + '0';
		octet /= 2;
	}
	write(1, result, 8);
}

int	main(void)
{
	print_bits(127);
}
