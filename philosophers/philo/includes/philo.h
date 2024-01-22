/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:19:37 by sangyepa          #+#    #+#             */
/*   Updated: 2024/01/18 22:01:20 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include	<stdio.h>	// printf
# include	<stdlib.h>	// malloc, free
# include	<unistd.h>	// usleep
# include	<pthread.h>	// pthread
# include	<sys/time.h>	// gettimeofday

# define SUCCESS	1
# define FAIL	0

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	// pthread_mutex_t 관련
	pthread_mutex_t	*forks;

	int				monitor;
}	t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	thread_id;
	int			eat_count;
	int			l_fork;
	int			r_fork;
	long		last_eat_time;
	long		last_thread_time;
	t_data		*data;
}	t_philo;



int		ft_atoi(const char *str);

int		init_data(t_data *data, int argc, char *argv[]);
int		init_philo(t_philo **philos, t_data *data);

void	print_error_exit(char *err_str);

#endif
