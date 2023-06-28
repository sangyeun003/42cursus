# 42Seoul
1. Libft
2. ft_printf

va_start(ap, format);
	if (*format == 'c')
		ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		ft_putunsignedint(va_arg(ap, unsigned int));
	else if (*format == 'p')
		ft_putp(va_arg(ap, void *));
	else if (*format == 'X')
		ft_putunsignedint_hex_large(va_arg(ap, unsigned int));
	else if (*format == 'x')
		ft_putunsignedint_hex_small(va_arg(ap, unsigned int));
	else if (*format == '%')
	{
		write(1, "%", 1);
		(*result)++;
	}
	va_end(ap);