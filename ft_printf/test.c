// gcc ft_printf.c ft_putunsignedint.c ft_putunsignedint_hex_large.c ft_putunsignedint_hex_small.c test.c ft_check.c libft.a
#include	"ft_printf.h"
#include	<stdio.h>

int	main(void)
{
	int a = 0;

	printf("%p\n", &a);
	ft_printf("%p", &a);
	return (0);
}
