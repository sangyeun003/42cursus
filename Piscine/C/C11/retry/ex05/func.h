/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:54:20 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/27 22:29:55 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include	<unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_sum(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_modulo(int a, int b);
int		ft_cal(int a, char c, int b);

#endif
