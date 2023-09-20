/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:41:54 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 20:52:25 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	set_game(t_game *game)
{
	int	i;

	game->step = 0;
	game->collection = 0;
	game->total_collection = 0;
	i = 0;
	while (game->map_str[i])
	{
		if (game->map_str[i] == 'C')
			game->total_collection++;
		else if (game->map_str[i] == 'P')
			game->map_str[i++] = '0';		// 처음 위치 '0'으로 세팅
	}
}
