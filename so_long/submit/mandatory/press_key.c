/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:46:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/08 17:40:32 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move_w(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] != 'P')
		i++;
	if (game->map_str[i - game->width] == '1' || \
		(game->map_str[i - game->width] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i - game->width] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	else if (game->map_str[i - game->width] == 'E' && \
		game->total_collection == game->got_collection)
		exit(0);
	else
	{
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
}

void	move_a(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] != 'P')
		i++;
	if (game->map_str[i - 1] == '1' || \
		(game->map_str[i - 1] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i - 1] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i - 1] = 'P';
		game->map_str[i] = '0';
	}
	else if (game->map_str[i - 1] == 'E' && \
		game->total_collection == game->got_collection)
		exit(0);
	else
	{
		game->step++;
		game->map_str[i - 1] = 'P';
		game->map_str[i] = '0';
	}
}

void	move_s(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] != 'P')
		i++;
	if (game->map_str[i + game->width] == '1' || \
		(game->map_str[i + game->width] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i + game->width] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i + game->width] = 'P';
		game->map_str[i] = '0';
	}
	else if (game->map_str[i + game->width] == 'E' && \
		game->total_collection == game->got_collection)
		exit(0);
	else
	{
		game->step++;
		game->map_str[i + game->width] = 'P';
		game->map_str[i] = '0';
	}
}

void	move_d(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] != 'P')
		i++;
	if (game->map_str[i + 1] == '1' || \
		(game->map_str[i + 1] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i + 1] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i + 1] = 'P';
		game->map_str[i] = '0';
	}
	else if (game->map_str[i + 1] == 'E' && \
		game->total_collection == game->got_collection)
		exit(0);
	else
	{
		game->step++;
		game->map_str[i + 1] = 'P';
		game->map_str[i] = '0';
	}
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
	ft_printf("Step: %d\n", game->step);
	return (0);
}
