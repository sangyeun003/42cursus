/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:48:34 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/01 19:30:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	display(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("MLX init failed!");
	game->window = mlx_new_window(game->mlx, 32 * game->width, \
		32 * game->height, "[so_long]");
	if (!game->window)
		print_error("Window opening failed!");
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		print_error("Malloc failed!");
	init_img(game);
	set_img(game);
}
