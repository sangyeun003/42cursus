/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:41:16 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/01 21:37:02 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	put_image_to_window(t_game *game, void *where, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, where, i * 32, j * 32);
}

void	put_image_by_char(t_game *game, int i, int j)
{
	if (game->map_str[i + j * game->width] == '1')
		put_image_to_window(game, game->img->wall, i, j);
	else if (game->map_str[i + j * game->width] == 'C')
		put_image_to_window(game, game->img->goal, i, j);
	else if (game->map_str[i + j * game->width] == 'E')
		put_image_to_window(game, game->img->exit, i, j);
	else if (game->map_str[i + j * game->width] == 'P')
		put_image_to_window(game, game->img->down, i, j);
	else if (game->map_str[i + j * game->width] == 'U')
		put_image_to_window(game, game->img->up, i, j);
	else if (game->map_str[i + j * game->width] == 'D')
		put_image_to_window(game, game->img->down, i, j);
	else if (game->map_str[i + j * game->width] == 'L')
		put_image_to_window(game, game->img->left, i, j);
	else if (game->map_str[i + j * game->width] == 'R')
		put_image_to_window(game, game->img->right, i, j);
	else if (game->map_str[i + j * game->width] == 'M')
		put_image_to_window(game, game->img->monster, i, j);
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
			put_image_by_char(game, i, j);
			j++;
		}
		i++;
	}
}
