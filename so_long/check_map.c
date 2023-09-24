/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:22:25 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/24 22:00:44 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	check_map(t_game *game)
{
	// int	i;
	// int	j;

	if (game->width <= 2 || game->height <= 2)
		print_error("Invalid Map!");
	
	// i = 0;
	// j = 2 * game->width - 1;
	// while (i < game->height - 2)
	// {
	// 	if (game->map_str[j] != '1' || \
	// 		game->map_str[j - game->width + 1] != '1')
	// 		print_error("Invalid Map!");
	// 	i++;
	// 	j += game->width;
	// }
}
