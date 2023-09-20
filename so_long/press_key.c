/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:46:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 21:57:32 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	move_w(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (game->map_str[i] == 'P')
		i++;
	if (game->map_str[i - game->width] == '1' || \
		(game->map_str[i - game->width] == 'E' && \
		(game->total_collection != game->collection)))
		return ;
	else if (game->map_str[i - game->width] == 'C')
	{
		game->collection++;
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	else
	{
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	set_img(img, game);
	printf("Step: %d\n", game->step);
}

void	move_a(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (game->map_str[i] == 'P')
		i++;
	if (game->map_str[i - game->width] == '1' || \
		(game->map_str[i - game->width] == 'E' && \
		(game->total_collection != game->collection)))
		return ;
	else if (game->map_str[i - game->width] == 'C')
	{
		game->collection++;
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	else
	{
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	set_img(img, game);
	printf("Step: %d\n", game->step);
}

void	move_s(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (game->map_str[i] == 'P')
		i++;
	if (game->map_str[i - game->width] == '1' || \
		(game->map_str[i - game->width] == 'E' && \
		(game->total_collection != game->collection)))
		return ;
	else if (game->map_str[i - game->width] == 'C')
	{
		game->collection++;
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	else
	{
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	set_img(img, game);
	printf("Step: %d\n", game->step);
}

void	move_d(t_game *game, t_img *img)
{
	int	i;

	i = 0;
	while (game->map_str[i] == 'P')
		i++;
	if (game->map_str[i - game->width] == '1' || \
		(game->map_str[i - game->width] == 'E' && \
		(game->total_collection != game->collection)))
		return ;
	else if (game->map_str[i - game->width] == 'C')
	{
		game->collection++;
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	else
	{
		game->step++;
		game->map_str[i - game->width] = 'P';
		game->map_str[i] = '0';
	}
	set_img(img, game);
	printf("Step: %d\n", game->step);
}

int	press_key(int keycode, t_game *game, t_img *img)
{
	if (keycode == W_KEY)
		move_w(game, img);
	else if (keycode == A_KEY)
		move_a(game, img);
	else if (keycode == S_KEY)
		move_s(game, img);
	else if (keycode == D_KEY)
		move_d(game, img);
	else if (keycode == ESC_KEY)
		exit(0);
	else
		return (0);
	printf("(%d, %d)\n", game->x, game->y);
	return (0);
}
