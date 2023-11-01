/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:41:16 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/01 18:37:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	put_image_to_window(t_game *game, void *where, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, where, i * 32, j * 32);
}

void	set_img(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->mlx, game->window);
	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			put_image_to_window(game, game->img->background, i, j);
			if (game->map_str[i + j * game->width] == '1')
				put_image_to_window(game, game->img->wall, i, j);
			else if (game->map_str[i + j * game->width] == 'C')
				put_image_to_window(game, game->img->goal, i, j);
			else if (game->map_str[i + j * game->width] == 'E')
				put_image_to_window(game, game->img->exit, i, j);
			else if (game->map_str[i + j * game->width] == 'P')
				put_image_to_window(game, game->img->character, i, j);
			j++;
		}
		i++;
	}
}
