/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:54:42 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/18 16:56:43 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	"../ft_printf/ft_printf.h"
#include	"../libft/libft.h"

void	get_bit(int signal, siginfo_t *siginfo, void *s)
{
	static int	bit;
	static char	c;

	s = 0;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			kill(siginfo->si_pid, SIGUSR1);
		else
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig;
	pid_t				pid;

	argv = 0;
	if (argc != 1)
	{
		ft_printf("Invalid argument!\nTry \"./server\"\n");
		exit(-1);
	}
	sig.sa_flags = SA_SIGINFO;	// sa_handler가 아니라 sa_sigaction을 사용하기 위해
	sig.sa_sigaction = &get_bit;
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	ft_printf("PID: %d\nWaiting for a message..\n", pid);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
