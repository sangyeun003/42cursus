/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:13:08 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/27 22:43:34 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

int	init_arg(t_arg *arg, int argc, char *argv[])
{
	arg->philo_num = ft_atoi(argv[1]);
	arg->lifespan = ft_atoi(argv[2]);
	arg->eat_span = ft_atoi(argv[3]);
	arg->sleep_span = ft_atoi(argv[4]);
	if (argc == 5)
		arg->eat_num = 0;
	else
	{
		arg->eat_num = ft_atoi(argv[5]);
		if (arg->eat_num <= 0)
			return (FAIL);
	}
	if (arg->philo_num <= 0 || arg->lifespan < 0 || arg->eat_span < 0 \
		|| arg->sleep_span < 0 || arg->eat_num < 0)
		return (FAIL);
	return (SUCCESS);
}
