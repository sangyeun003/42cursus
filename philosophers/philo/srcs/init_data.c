/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:13:08 by sangyepa          #+#    #+#             */
/*   Updated: 2024/01/18 21:57:05 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

int	init_data(t_data *data, int argc, char *argv[])
{
	int	i;
	
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->monitor = 0;
	if (argc == 5)
		data->num_of_eat = -1;
	else
	{
		data->num_of_eat = ft_atoi(argv[5]);
		if (data->num_of_eat < 0)
			return (FAIL);
	}
	if (data->num_of_philo <= 0 || data->time_to_die < 0 || data->time_to_eat < 0 \
		|| data->time_to_sleep < 0)
		return (FAIL);
	data->forks = malloc(data->num_of_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (FAIL);
	i = 0;
	while (i < data->num_of_eat)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
