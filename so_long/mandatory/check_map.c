/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:22:25 by sangyepa          #+#    #+#             */
/*   Updated: 2023/10/06 17:41:12 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*ft_strndup(char *s, int n)
{
	int		i;
	char	*result;

	result = (char *)malloc((n + 1) * sizeof(char));
	if (!result)
		print_error("Malloc failed!");
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**make_2d_map(t_game *game)
{
	int		i;
	char	**result;

	result = (char **)malloc(game->height * sizeof(char *));
	if (!result)
		print_error("Malloc failed!");
	i = 0;
	while (i < game->height)
	{
		result[i] = ft_strndup(game->map_str + i * game->width, game->width);
		if (!result[i])
			print_error("Malloc failed!");
		i++;
	}
	result[i] = 0;
	return (result);
}

void	check_map(t_game *game)
{
	if (game->width <= 2 || game->height <= 2)
		print_error("Map is too small!");
	game->map_2d = make_2d_map(game);
	if (!game->map_2d)
		print_error("Malloc failed!");
}
