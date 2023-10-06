/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:07 by sangyepa          #+#    #+#             */
/*   Updated: 2023/10/06 22:44:12 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -lmlx -framework OpenGl -framework AppKit -Imlx main.c
// arch -x86_64 gcc *.c -I. -Lmlx -lmlx -framework Metal -framework Metalkit
#include	"so_long.h"

int	dfs_for_collection(int x, int y, char **map)
{
	int	count;

	count = 0;
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		count++;
	map[y][x] = 'V';
	count += dfs_for_collection(x + 1, y, map);
	printf("1\n");
	count += dfs_for_collection(x - 1, y, map);
	printf("2\n");
	// count += dfs_for_collection(x, y + 1, map);
	// printf("3\n");
	// count += dfs_for_collection(x, y - 1, map);
	// printf("4\n");
	return (count);
}

int	dfs_for_exit(int x, int y, char **map)
{
	int	count;

	count = 0;
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'E')
		count++;
	map[y][x] = 'V';
	count += dfs_for_collection(x + 1, y, map);
	count += dfs_for_collection(x - 1, y, map);
	count += dfs_for_collection(x, y + 1, map);
	count += dfs_for_collection(x, y - 1, map);
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
			print_error("Malloc failed!");
		// printf("%s\n", result[i]);
		i++;
	}
	// printf("%s\n", game->map_str);
	result[i] = 0;
	return (result);
}

int	escapable(t_game *game)
{
	int		x;
	int		y;
	int		collection_num;
	int		exit_num;
	char	**dfs_map;

	x = game->x;
	y = game->y;
printf("%d, %d\n", x, y);
	collection_num = 0;
	exit_num = 0;
	dfs_map = map_dup(game);
	if (!dfs_map)
		print_error("Malloc failed!");
	collection_num += dfs_for_collection(x, y, dfs_map);
	// exit_num += dfs_for_exit(x, y, dfs_map);
	// if (collection_num != game->total_collection || exit_num != 1)
	// 	print_error("Cannot escape!");
	return (1);
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
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.window, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_loop(game.mlx);
	exit(0);
}
