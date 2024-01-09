#include    <unistd.h>
#include    <stdarg.h>

int put_string(char *s)
{
    int len;
    
    if (!s)
        s = "(null)";
    len = 0;
    while (*s)
    {
        len += write(1, s, 1);
        s++;
    }
    return (len);
}

void    put_number_base(long long num, int base, int *len)
{
    char    *hexa = "0123456789abcdef";
    
    if (num < 0)
    {
        num *= -1;
        *len += write(1, "-", 1);
    }
    if (num >= base)
        put_number_base(num / base, base, len);
    *len += write(1, &hexa[num % base], 1);
}

int ft_printf(const char *format, ...)
{
    int     len;
    va_list ap;

    va_start(ap, format);
    len = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 's')
                len += put_string(va_arg(ap, char *));
            else if (*format == 'd')
                put_number_base((long long)va_arg(ap, long long), 10, &len);
            else if (*format == 'x')
                put_number_base((long long)va_arg(ap, unsigned int), 16, &len);
        }
        else
            len += write(1, format, 1);
        format++;
    }
    va_end(ap);
    return (len);
}

int	main(void)
{
	ft_printf("%d\n", ft_printf("%d %s %x %s\n", 2147483647, "hello", 324, 0));
	return (0);
}

