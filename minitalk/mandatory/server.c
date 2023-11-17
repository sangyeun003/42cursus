/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:16:49 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/17 23:30:34 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	"../ft_printf/ft_printf.h"
#include	"../libft/libft.h"

void	get_bit(int signal)
{
	static int	bit = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	argv = 0;
	if (argc != 1)
	{
		ft_printf("Invalid argument!\nTry: ./server\n");
		exit(-1);
	}
	pid = getpid();
	ft_printf("PID: %d\nWaiting for a message..\n", pid);
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
		pause();
	return (0);
}
