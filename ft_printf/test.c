#include	"ft_printf.h"
#include	<stdio.h>

int	main(void)
{
	ft_printf("%c %s %d %u %i %x %X", 'a', "abc", 10, 100, 1000, 333, 333);
	printf("\n%c %s %d %u %i %x %X", 'a', "abc", 10, 100, 1000, 333, 333);
	return (0);
}
