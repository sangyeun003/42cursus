/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:07 by sangyepa          #+#    #+#             */
/*   Updated: 2023/10/02 23:11:48 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -lmlx -framework OpenGl -framework AppKit -Imlx main.c
// arch -x86_64 gcc *.c -I. -Lmlx -lmlx -framework Metal -framework Metalkit
#include	"so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		print_error("Invalid argument!");
	read_map(argv[1], &game);
	check_map(&game);
	// printf("%s\n", game.map_str);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit(1);
	game.window = mlx_new_window(game.mlx, 32 * game.width, \
		32 * game.height, "[so_long]");
	if (!game.window)
		exit(1);
	init_game(&game);
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.window, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_loop(game.mlx);
	exit(0);
}
