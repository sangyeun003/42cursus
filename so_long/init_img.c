/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:47:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/23 18:04:05 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	init_img(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		exit(1);
	game->img->background = mlx_xpm_file_to_image(game->mlx, \
		"./images/background.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->background)
		exit(1);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, \
		"./images/wall.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->wall)
		exit(1);
	game->img->character = mlx_xpm_file_to_image(game->mlx, \
		"./images/down.xpm", &(game->img->width), &(game->img->height));
	if (!game->img->character)
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
