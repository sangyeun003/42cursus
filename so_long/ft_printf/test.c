#include	"ft_printf.h"
#include	<stdio.h>

int	main(void)
{
	int a = 0;

	// printf(" %d", printf("%c %s %d %i %u %x %X %%", 'a', "abcde", 2147483647, 2147483647, 4294967295, 52345, 52345));
	// printf("\n");
	// ft_printf("%d", ft_printf(""));
	ft_printf(" %d", ft_printf("%c %s %d %i %u %x %X %%", 'a', "abcde", 2147483647, 2147483647, 4294967295, 52345, 52345));
	// printf("% %s\n");
	// ft_printf("% %d", 10);
	printf("\n");
	printf(" %d\n", printf("%p", 2147483647));
	ft_printf(" %d", ft_printf("%p", 2147483647));
	printf("\n");
	printf("%d", printf(" NULL %s NULL ", NULL));
	printf("\n");
	ft_printf("%d", ft_printf(" NULL %s NULL ", 0));

	return (0);
}
