/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:07 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/23 17:52:41 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -lmlx -framework OpenGl -framework AppKit -Imlx main.c
// gcc -I . *.c -L mlx/ -lmlx -framework OpenGL -framework AppKit
// gcc -I . *.c -L mlx/ -lmlx -framework OpenGL -framework AppKit -arch x86_64
#include	"so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit(1);
	read_map(argv[1], &game);
	init_game(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit(1);
	game.window = mlx_new_window(game.mlx, 32 * game.width, \
		32 * game.height, "so_long");
	init_img(&game);
	set_img(&game);
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.window, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_loop(game.mlx);
	exit(0);
}
