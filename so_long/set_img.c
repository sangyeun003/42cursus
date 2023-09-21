/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:41:16 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 20:59:55 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	set_img(t_img *img, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			mlx_put_image_to_window(game->mlx, game->window, \
				img->background, i * 32, j * 32);
			if (game->map_str[i + j * game->width] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
					img->wall, i * 32, j * 32);
			else if (game->map_str[i + j * game->width] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
					img->goal, i * 32, j * 32);
			else if (game->map_str[i + j * game->width] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
					img->exit, i * 32, j * 32);
			else if (game->map_str[i + j * game->width] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
					img->character, i * 32, j * 32);
			j++;
		}
		i++;
	}
}
