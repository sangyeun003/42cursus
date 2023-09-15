/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:56 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/15 21:54:03 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	"./mlx/mlx.h"

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

void	pos_init(t_pos *pos);
int		close_window(void);
int		press_key(int keycode, t_pos *pos);

#endif