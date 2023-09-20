/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:07 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 11:19:20 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -lmlx -framework OpenGl -framework AppKit -Imlx main.c
// gcc -I . *.c -L mlx/ -lmlx -framework OpenGL -framework AppKit
// gcc -I . *.c -L mlx/ -lmlx -framework OpenGL -framework AppKit -arch x86_64
#include	"so_long.h"

int	main(int argc, char **argv)
{
	t_img	img;
	t_game	game;

	read_map(argv[1], &game);
	printf("=====\n");
	game.mlx = mlx_init(); // mlx포인터 생성
	if (!game.mlx)
		exit(1);
	game.window = mlx_new_window(game.mlx, 32 * game.width, 32 * game.height, "so_long"); // 윈도우 띄우기
	img_init(&img, &game);
	set_img_to_map(img, &game);
	// mlx_put_image_to_window(game.mlx, win, up_img, 0, 0);
	// mlx_put_image_to_window(mlx, win, down_img, 0, 0);
	// mlx_put_image_to_window(mlx, win, right_img, 64, 0);
	// mlx_put_image_to_window(mlx, win, left_img, 0, 32);

	mlx_hook(game.window, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 0, &press_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
