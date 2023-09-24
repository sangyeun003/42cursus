/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:41:58 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/10 18:50:14 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include	<unistd.h>
# include	<stdarg.h>
# include	<stdint.h>

int		ft_printf(const	char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putp(uintptr_t nbr, int *result);
void	ft_check(va_list *ap, const char *format, int *result);
void	ft_putunsignedint(unsigned int n, int *result);
void	ft_putunsignedint_hex(unsigned int nbr, int *result, char x);
void	ft_put_integer(int n, int *result);

#endif