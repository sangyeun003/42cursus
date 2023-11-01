/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:56 by sangyepa          #+#    #+#             */
/*   Updated: 2023/10/02 17:21:14 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	"../mlx/mlx.h"
# include	"../ft_printf/ft_printf.h"
# include	"get_next_line_bonus.h"

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17

# define TRUE 1
# define FALSE 0

typedef struct s_img
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*background;
	void	*wall;
	void	*goal;
	void	*exit;
	void	*monster;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		exit_num;
	int		character_num;
	int		got_collection;
	int		total_collection;
	int		step;
	char	*map_str;
	void	*mlx;
	void	*window;
	t_img	*img;
}	t_game;

void	init_img(t_game *game);
char	*ft_strjoin_without_newline(char *s1, char *s2);
char	*ft_strdup_without_newline(char *str);

void	read_map(char *file_name, t_game *game);
void	check_map(t_game *game);
void	set_img(t_game *game);
void	init_game(t_game *game);

int		close_window(void);
int		press_key(int keycode, t_game *game);
void	print_error(char *s);

void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);

#endif