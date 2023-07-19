/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:32:58 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/27 22:51:03 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"func.h"

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	if (argv[2][1] != 0 || (argv[2][0] != '+' && argv[2][0] != '-'
				&& argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '%'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (ft_strcmp(argv[3], "0") == 0)
	{
		if (argv[2][0] == '/')
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		else if (argv[2][0] == '%')
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
	}
	ft_putnbr(ft_cal(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3])));
	write(1, "\n", 1);
	return (0);
}
