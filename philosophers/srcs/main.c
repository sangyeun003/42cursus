/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:19:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/12/27 22:25:26 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		print_error_exit("Invalid argument!");
	if (init_arg(&arg, argc, argv) == FAIL)
		print_error_exit("Negative number exists!");

	return (0);
}
