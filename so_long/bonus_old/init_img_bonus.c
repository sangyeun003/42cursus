/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:47:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/10/02 17:22:49 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	init_img(t_game *game)
{
	game->img->background = mlx_xpm_file_to_image(game->mlx, \
		"./images/background.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->background)
		exit(1);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, \
		"./images/wall.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->wall)
		exit(1);
	game->img->up = mlx_xpm_file_to_image(game->mlx, \
		"./images/up.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->up)
		exit(1);
	game->img->down = mlx_xpm_file_to_image(game->mlx, \
		"./images/down.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->down)
		exit(1);
	game->img->left = mlx_xpm_file_to_image(game->mlx, \
		"./images/left.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->left)
		exit(1);
	game->img->right = mlx_xpm_file_to_image(game->mlx, \
		"./images/right.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->right)
		exit(1);
	game->img->monster = mlx_xpm_file_to_image(game->mlx, \
		"./images/monster.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->monster)
		exit(1);
	game->img->goal = mlx_xpm_file_to_image(game->mlx, \
		"./images/goal.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->goal)
		exit(1);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, \
		"./images/exit.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->exit)
		exit(1);
}
