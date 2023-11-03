/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:07 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/03 17:34:33 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	dfs_for_collection(t_game *game, int x, int y, char **map)
{
	int	count;

	count = 0;
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V' \
		|| map[y][x] == 'M')
		return (0);
	if (map[y][x] == 'C')
		count++;
	map[y][x] = 'V';
	count += dfs_for_collection(game, x + 1, y, map);
	count += dfs_for_collection(game, x - 1, y, map);
	count += dfs_for_collection(game, x, y + 1, map);
	count += dfs_for_collection(game, x, y - 1, map);
	return (count);
}

int	dfs_for_exit(t_game *game, int x, int y, char **map)
{
	int	count;

	count = 0;
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'M')
		return (0);
	if (map[y][x] == 'E')
		count++;
	map[y][x] = '0';
	count += dfs_for_exit(game, x + 1, y, map);
	count += dfs_for_exit(game, x - 1, y, map);
	count += dfs_for_exit(game, x, y + 1, map);
	count += dfs_for_exit(game, x, y - 1, map);
	return (count);
}

char	**map_dup(t_game *game)
{
	int		i;
	char	**result;

	result = (char **)malloc((game->height + 1) * sizeof(char *));
	if (!result)
		print_error("Malloc failed!");
	i = 0;
	while (i < game->height)
	{
		result[i] = ft_strdup(game->map_2d[i]);
		if (!result[i])
		{
			i--;
			while (i >= 0)
				free(result[i--]);
			free(result);
			print_error("Malloc failed!");
		}
		i++;
	}
	result[i] = 0;
	return (result);
}

void	escapable(t_game *game)
{
	int		i;
	int		collection_num;
	int		exit_num;
	char	**real_map;

	real_map = map_dup(game);
	if (!real_map)
		print_error("Malloc failed!");
	collection_num = dfs_for_collection(game, game->x, game->y, real_map);
	exit_num = dfs_for_exit(game, game->x, game->y, real_map);
	i = 0;
	while (real_map[i])
		free(real_map[i++]);
	free(real_map);
	if (collection_num != game->total_collection || exit_num != 1)
		print_error("Cannot escape!");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error("Invalid argument!");
	read_map(argv[1], &game);
	check_map(&game);
	init_game(&game);
	escapable(&game);
	display(&game);
	view_step(&game);
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.window, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_loop(game.mlx);
	exit(0);
}
