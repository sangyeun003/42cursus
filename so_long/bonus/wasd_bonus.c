/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:19:00 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/01 21:55:25 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	is_character(char c)
{
	return (c == 'P' || c == 'U' || c == 'D' || c == 'L' || c == 'R');
}

void	move_w(t_game *game)
{
	int	i;

	i = 0;
	while (!is_character(game->map_str[i]))
		i++;
	if (game->map_str[i - game->width] == '1' || \
		(game->map_str[i - game->width] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i - game->width] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i - game->width] = 'U';
		game->map_str[i] = '0';
	}
	else if ((game->map_str[i - game->width] == 'E' && game->total_collection \
			== game->got_collection) || game->map_str[i - game->width] == 'M')
		meet_monster(game->map_str[i - game->width]);
	else
	{
		game->step++;
		game->map_str[i - game->width] = 'U';
		game->map_str[i] = '0';
	}
}

void	move_a(t_game *game)
{
	int	i;

	i = 0;
	while (!is_character(game->map_str[i]))
		i++;
	if (game->map_str[i - 1] == '1' || \
		(game->map_str[i - 1] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i - 1] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i - 1] = 'L';
		game->map_str[i] = '0';
	}
	else if ((game->map_str[i - 1] == 'E' && game->total_collection \
			== game->got_collection) || game->map_str[i - 1] == 'M')
		meet_monster(game->map_str[i - 1]);
	else
	{
		game->step++;
		game->map_str[i - 1] = 'L';
		game->map_str[i] = '0';
	}
}

void	move_s(t_game *game)
{
	int	i;

	i = 0;
	while (!is_character(game->map_str[i]))
		i++;
	if (game->map_str[i + game->width] == '1' || \
		(game->map_str[i + game->width] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i + game->width] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i + game->width] = 'D';
		game->map_str[i] = '0';
	}
	else if ((game->map_str[i + game->width] == 'E' && game->total_collection \
			== game->got_collection) || game->map_str[i + game->width] == 'M')
		meet_monster(game->map_str[i + game->width]);
	else
	{
		game->step++;
		game->map_str[i + game->width] = 'D';
		game->map_str[i] = '0';
	}
}

void	move_d(t_game *game)
{
	int	i;

	i = 0;
	while (!is_character(game->map_str[i]))
		i++;
	if (game->map_str[i + 1] == '1' || \
		(game->map_str[i + 1] == 'E' && \
		(game->total_collection != game->got_collection)))
		return ;
	else if (game->map_str[i + 1] == 'C')
	{
		game->got_collection++;
		game->step++;
		game->map_str[i + 1] = 'R';
		game->map_str[i] = '0';
	}
	else if ((game->map_str[i + 1] == 'E' && game->total_collection \
			== game->got_collection) || game->map_str[i + 1] == 'M')
		meet_monster(game->map_str[i + 1]);
	else
	{
		game->step++;
		game->map_str[i + 1] = 'R';
		game->map_str[i] = '0';
	}
}
