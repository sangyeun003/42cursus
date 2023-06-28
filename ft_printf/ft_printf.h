/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:41:58 by sangyepa          #+#    #+#             */
/*   Updated: 2023/06/28 12:27:21 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>
# include	"./libft/libft.h"

int		ft_printf(const	char *format, ...);
void	ft_putunsignedint(unsigned int n);
void	ft_putunsignedint_hex_large(unsigned int nbr);
void	ft_putunsignedint_hex_small(unsigned int nbr);

int		main(void);

#endif