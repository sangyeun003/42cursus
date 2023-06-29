/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:41:58 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/29 18:41:16 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>

int		ft_printf(const	char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putp(unsigned long long nbr, int *result);
void	ft_check(va_list *ap, const char *format, int *result);
void	ft_putunsignedint(unsigned int n, int *result);
void	ft_putunsignedint_hex_large(unsigned int nbr, int *result);
void	ft_putunsignedint_hex_small(unsigned int nbr, int *result);
void	ft_putnbr(int n, int *result);

#endif