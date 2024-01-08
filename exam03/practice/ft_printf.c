#include	<stdarg.h>
#include	<unistd.h>

int	put_string(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (*s)
		len += write(1, s++, 1);
	return (len);
}

void	put_number(long long num, int base, int *length)
{
	char	*hexa = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		*length += write(1, "-", 1);
	}
	if (num >= base)
		put_number(num / base, base, length);
	*length += write(1, &hexa[num % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	ap;
	
	va_start(ap, format);
	length = 0;
	while (*format)
	{
		if ((*format == '%' && *(format + 1) == 's') || (*format == '%' && *(format + 1) == 'd') || (*format == '%' && *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				length += put_string(va_arg(ap, char *));
			else if (*format == 'd')
				put_number((long long)va_arg(ap, int), 10, &length);
			else if (*format == 'x')
				put_number((long long)va_arg(ap, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (length);
}

int	main(void)
{
	ft_printf("%d\n", ft_printf("%d %s %x %s\n", 2147483647, "hello", 324, 0));
	return (0);
}
