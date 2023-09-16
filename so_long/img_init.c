/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:47:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/16 15:57:46 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	img_init(t_img *img, t_game *game)
{
	img->background = mlx_xpm_file_to_image(game->mlx, \
				"./images/background.xpm", &(img->width), &(img->height));
	img->wall = mlx_xpm_file_to_image(game->mlx, \
				"./images/wall.xpm", &(img->width), &(img->height));
	img->up = mlx_xpm_file_to_image(game->mlx, \
				"./images/up.xpm", &(img->width), &(img->height));
	img->down = mlx_xpm_file_to_image(game->mlx, \
				"./images/down.xpm", &(img->width), &(img->height));
	img->left = mlx_xpm_file_to_image(game->mlx, \
				"./images/left.xpm", &(img->width), &(img->height));
	img->right = mlx_xpm_file_to_image(game->mlx, \
				"./images/right.xpm", &(img->width), &(img->height));
	img->goal = mlx_xpm_file_to_image(game->mlx, \
				"./images/goal.xpm", &(img->width), &(img->height));
	img->exit = mlx_xpm_file_to_image(game->mlx, \
				"./images/exit.xpm", &(img->width), &(img->height));
}
