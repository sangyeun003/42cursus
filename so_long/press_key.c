/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:46:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/19 20:27:57 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->y++;
	else if (keycode == A_KEY)
		game->x--;
	else if (keycode == S_KEY)
		game->y--;
	else if (keycode == D_KEY)
		game->x++;
	else if (keycode == ESC_KEY)
		exit(0);
	else
		return (0);
	printf("(%d, %d)\n", game->x, game->y);
	return (0);
}
