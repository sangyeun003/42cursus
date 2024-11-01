/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:28:03 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 16:17:23 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define TRUE	1
# define FALSE	0
# define SUCCESS 1
# define FAIL 0
# define ERROR -1
# include	<unistd.h>
# include	<stdlib.h>
# include	"get_next_line_bonus.h"

typedef struct s_node
{
	int				data;
	int				index;
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

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char *str, char *charset);
int		ft_check_invalid_input(int argc, char **argv);
void	ft_is_overlaping(t_deque *pdeq, int data);
void	ft_parsing(int argc, char **argv, t_deque *pdeq);
void	ft_error(void);

void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);

void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);

void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);

int		is_sorted(t_deque deq);
void	a_to_b(t_deque *a, t_deque *b);
void	b_to_a(t_deque *a, t_deque *b);
void	sort_2(t_deque *a);
void	sort_3(t_deque *a);

int		find_min_idx(t_deque *pdeq);
int		find_max_idx(t_deque *pdeq);
int		index_to_data(t_deque *pdeq, int index);
int		find_location_in_a(t_deque *a, int b_num);
int		return_index(t_deque *pdeq, int index);
int		cal_total_command_num(int a_command_num, int b_command_num);
int		greedy(t_deque *a, t_deque *b);

int		ft_strcmp(char *s1, char *s2);

int		main(int argc, char *argv[]);

#endif