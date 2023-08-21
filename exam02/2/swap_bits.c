#include	<unistd.h>

// void	swap_bits(unsigned char octet)
// {
// 	char	result[9];
// 	char	o1;
// 	char	o2;

// 	o1 = octet * 16;
// 	o2 = octet / 16;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		result[3 - i] = o1 % 2 + '0';
// 		o1 /= 2;
// 	}
// 	for (int i = 4; i < 8; i++)
// 	{
// 		result[7 - i] = o2 % 2 + '0';
// 		o2 /= 2;
// 	}
// 	write(1, result, 8);
// }

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

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main(void)
{
	print_bits(swap_bits(65));
}
