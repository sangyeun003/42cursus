/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:03:26 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/15 18:59:05 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf/ft_printf.h"
#include	"../libft/libft.h"

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid argument!\nTry: ./client [PID] [MESSAGE]");
		exit(-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99999)
	{
		ft_printf("Invalid argument!\n");
		exit(-1);
	}
	send(pid, argv[2]);
	return (0);
}
