/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_to_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:41:16 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/19 20:24:16 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	set_img_to_map(t_img img, t_game *game)
{
	int	i;
	int	map_str_len;

	i = 0;
	map_str_len = ft_strlen(game->map_str);
	while (i < map_str_len)
		mlx_put_image_to_window(game->mlx, game->window, \
			img.background, map_str_len % game->width, map_str_len / game->height);
}