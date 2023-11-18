/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:54:42 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/18 11:42:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	"../ft_printf/ft_printf.h"
#include	"../libft/libft.h"

void	get_bit(int signal, siginfo_t *siginfo, void *s)
{
	static int	bit;
	static char	c;
	pid_t		pid;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	pid = siginfo->si_pid;	// client의 pid
	if (bit == 8)
	{
		if (c == NULL)
			kill(pid, SIGUSR1);
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
	sig.sa_flags = SA_SIGINFO;
	// sigaction에 함수 매핑
	sig.sa_sigaction = &get_bit;
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	ft_printf("PID: %d\nWaiting for a message..\n", pid);
	// SIGUSR1, SIGUSR2가 입력되면 sigaction에 연결된 함수 호출
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)	// signal 받을 때까지 CPU 다른 일하면서 기다림
		pause();
	return (0);
}
