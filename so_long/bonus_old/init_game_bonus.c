/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:41:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/10/02 17:22:45 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	check_map_component(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i])
	{
		if (game->map_str[i] == 'C')
			game->total_collection++;
		else if (game->map_str[i] == 'E')
			game->exit_num++;
		else if (game->map_str[i] == 'P')
			game->character_num++;
		else if (game->map_str[i] != '0' && game->map_str[i] != '1')
			print_error("Invalid character exists!");
		i++;
	}
	if (game->total_collection < 1 || game->exit_num != 1 || \
		game->character_num != 1)
		print_error("Invalid component!");
}

void	init_game(t_game *game)
{
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		print_error("Malloc failed!");
	init_img(game);
	set_img(game);
	game->step = 0;
	game->exit_num = 0;
	game->character_num = 0;
	game->got_collection = 0;
	game->total_collection = 0;
	check_map_component(game);
}
