/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:03:23 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/15 17:48:08 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc server.c -L ../ft_printf -lftprintf
#include	<unistd.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"../ft_printf/ft_printf.h"

int	main(void)
{
	while (1)
		printf("%d\n", getpid());
	return (0);
}
