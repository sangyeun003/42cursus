/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:19:37 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/28 20:26:43 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include	<stdio.h>	// printf
# include	<stdlib.h>	// malloc, free
# include	<unistd.h>	// usleep
# include	<string.h>	// memset
# include	<pthread.h>	// pthread
# include	<sys/time.h>	// gettimeofday

# define SUCCESS	1
# define FAIL	0

typedef struct s_arg
{
	int	philo_num;
	int	lifespan;
	int	eat_span;
	int	sleep_span;
	int	eat_num;
}	t_arg;

typedef struct s_philo
{
	
}	t_philo;



int		ft_atoi(const char *str);

int		init_arg(t_arg *arg, int argc, char *argv[]);

void	print_error_exit(char *err_str);

#endif
