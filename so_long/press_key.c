/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:46:09 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/15 21:48:50 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	press_key(int keycode, t_pos *pos)
{
	if (keycode == W_KEY)
		pos->y++;
	else if (keycode == A_KEY)
		pos->x--;
	else if (keycode == S_KEY)
		pos->y--;
	else if (keycode == D_KEY)
		pos->x++;
	else if (keycode == ESC_KEY)
		exit(0);
	else
		return (0);
	printf("(%d, %d)\n", pos->x, pos->y);
	return (0);
}
