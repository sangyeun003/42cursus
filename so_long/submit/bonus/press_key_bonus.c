/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:46:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/08 17:54:15 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	view_step(t_game *game)
{
	char	*step;
	char	*result;

	step = ft_itoa(game->step);
	if (!step)
		print_error("Malloc failed!");
	result = step_char(step);
	free(step);
	if (!result)
		print_error("Malloc failed!");
	mlx_string_put(game->mlx, game->window, 0, \
		game->height * 32 + 16, 0x00FFFFFF, result);
	free(result);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		move_w(game);
	else if (keycode == A_KEY)
		move_a(game);
	else if (keycode == S_KEY)
		move_s(game);
	else if (keycode == D_KEY)
		move_d(game);
	else if (keycode == ESC_KEY)
		close_window(game);
	else
		return (0);
	set_img(game);
	view_step(game);
	return (0);
}
