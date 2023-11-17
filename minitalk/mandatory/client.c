/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:17:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/17 23:31:15 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../ft_printf/ft_printf.h"
#include	"../libft/libft.h"
#include	<signal.h>

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

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3 || argv[2][0] == 0)
	{
		ft_printf("Invalid Argument!\nTry: ./client [PID] [MSG]\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99999)
	{
		ft_printf("Wrong PID!\n");
		return (-1);
	}
	send_str(pid, argv[2]);
	return (0);
}
