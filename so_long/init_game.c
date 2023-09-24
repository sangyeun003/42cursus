/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:41:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/24 18:08:57 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	init_game(t_game *game)
{
	int	i;

	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		exit(1);
	init_img(game);
	set_img(game);
	game->step = 0;
	game->collection = 0;
	game->total_collection = 0;
	i = 0;
	while (game->map_str[i])
	{
		if (game->map_str[i] == 'C')
			game->total_collection++;
		i++;
	}
}
