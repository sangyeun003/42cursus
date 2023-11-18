/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:54:44 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/18 11:32:04 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	"../ft_printf/ft_printf.h"
#include	"../libft/libft.h"

void	send_bit(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((1 << bit) & c) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);	// for delay 왜?
		bit++;
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(pid, str[i]);
		i++;
	}
	send_bit(pid, '\n');
	send_bit(pid, 0);	// 왜 보낼까?
}

void	check_ack(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Sending Success!\n");
	exit(0);	// ACK 받고 client 종료
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3 || argv[2][0] == 0)
	{
		ft_printf("Invalid Argument!\nTry \"./client [PID] [MSG]\"\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99999)
	{
		ft_printf("Wrong PID!\n");
		return (-1);
	}
	signal(SIGUSR1, check_ack);
	send_str(pid, argv[2]);
	return (0);
}
