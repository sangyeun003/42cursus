/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:22:25 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 16:45:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	check_map(t_game game)
{
	if (game.width * game.height != (ft_strlen(game.map_str)))
		return (FALSE);
	// 첫 width개, 마지막 width개 모두 벽(1)이어야 함.
	// 각 행의 처음과 마지막 벽(0)이어야 함.

	return (TRUE);
}
