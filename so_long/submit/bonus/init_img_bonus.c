/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:47:55 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/01 21:14:26 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	ft_xpm_to_image(t_game *game, void **where, char *file)
{
	*where = mlx_xpm_file_to_image(game->mlx, file, \
					&(game->img->width), &(game->img->height));
	if (!*where)
		print_error("Image initialize failed!");
}

void	init_img(t_game *game)
{
	ft_xpm_to_image(game, &(game->img->background), "./images/background.xpm");
	ft_xpm_to_image(game, &(game->img->wall), "./images/wall.xpm");
	ft_xpm_to_image(game, &(game->img->up), "./images/up.xpm");
	ft_xpm_to_image(game, &(game->img->down), "./images/down.xpm");
	ft_xpm_to_image(game, &(game->img->left), "./images/left.xpm");
	ft_xpm_to_image(game, &(game->img->right), "./images/right.xpm");
	ft_xpm_to_image(game, &(game->img->monster), "./images/monster.xpm");
	ft_xpm_to_image(game, &(game->img->goal), "./images/goal.xpm");
	ft_xpm_to_image(game, &(game->img->exit), "./images/exit.xpm");
}
