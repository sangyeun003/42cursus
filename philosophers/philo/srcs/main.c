/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:19:09 by sangyepa          #+#    #+#             */
/*   Updated: 2024/01/17 17:36:10 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"
// 먹기->자기->생각하기
int	main(int argc, char *argv[])	// 철학자수 수명 밥먹는시간 잠자는시간 [총식사횟수]
{
	t_data	data;

	if (argc != 5 && argc != 6)
		print_error_exit("Invalid argument!");
	if (init_data(&data, argc, argv) == FAIL)
		print_error_exit("Invalid argument!");

	return (0);
}
