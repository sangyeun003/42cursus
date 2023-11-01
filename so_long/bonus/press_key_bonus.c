/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:46:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/01 21:18:56 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		move_w(game);
	else if (keycode == A_KEY)
		move_a(game);
	else if (keycode == S_KEY)
		move_s(game);
	else if (keycode == D_KEY)
		move_d(game);
	else if (keycode == ESC_KEY)
		exit(0);
	else
		return (0);
	set_img(game);
	ft_printf("Step: %d\n", game->step);
	return (0);
}
