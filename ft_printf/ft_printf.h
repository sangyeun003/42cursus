/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:41:58 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/28 17:16:20 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>
// # include	"libft.h"

int		ft_printf(const	char *format, ...);
void	ft_putunsignedint(unsigned int n);
void	ft_putunsignedint_hex_large(unsigned int nbr);
void	ft_putunsignedint_hex_small(unsigned int nbr);
void	ft_putp(void *address);
void	ft_check(va_list ap, const char *format, int *result);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);

int		main(void);

#endif