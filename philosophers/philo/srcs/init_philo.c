/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:11 by sangyepa          #+#    #+#             */
/*   Updated: 2024/01/18 21:53:10 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

int	init_philo(t_philo **philos, t_data *data)
{
	int	i;

	*philos = malloc(data->num_of_philo * sizeof(t_philo));
	if (!*philos)
		return (FAIL);
	i = 0;
	while (i < data->num_of_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_count = 0;
		(*philos)[i].l_fork = i;
		(*philos)[i].r_fork = (i + 1) % data->num_of_philo;
		(*philos)[i].last_eat_time = 0;
		(*philos)[i].last_thread_time = 0;
		(*philos)[i].data = data;
		i++;
	}
	return (SUCCESS);
}