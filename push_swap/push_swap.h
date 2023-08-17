/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:28:03 by sangyepa          #+#    #+#             */
/*   Updated: 2023/08/17 22:06:11 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define TRUE	1
# define FALSE	0
# include	<unistd.h>
# include	<stdlib.h>

# include	<stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_deque;

void	ft_deque_init(t_deque *pdeq);
int		ft_deque_is_empty(t_deque *pdeq);
void	ft_deque_add_first(t_deque *pdeq, int data);
void	ft_deque_add_last(t_deque *pdeq, int data);
int		ft_deque_remove_first(t_deque *pdeq);
int		ft_deque_remove_last(t_deque *pdeq);
int		ft_deque_get_first(t_deque *pdeq);
int		ft_deque_get_last(t_deque *pdeq);

void	ft_free_deque(t_deque *pdeq);

int		ft_atoi(const char *str, t_deque *pdeq);
int		ft_isdigit(int c);
char	**ft_split(char *str, char *charset);
int		ft_check_invalid_input(int argc, char **argv);
int		ft_is_overlaping(t_deque *pdeq, int data);
void	ft_parsing(int argc, char **argv, t_deque *pdeq);
void	ft_error(t_deque *pdeq);

int		main(int argc, char *argv[]);

#endif