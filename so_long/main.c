/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:07 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/16 16:00:09 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -lmlx -framework OpenGl -framework AppKit -Imlx main.c

#include	"so_long.h"

int	main(void)
{
	t_img	img;
	t_game	game;
	t_pos	pos;

	game.mlx = mlx_init(); // mlx포인터 생성
	game.window = mlx_new_window(game.mlx, 500, 500, "img test"); // 윈도우 띄우기
	pos_init(&pos); // 구조체 값 초기설정

	img_init(&img, &game);

	mlx_put_image_to_window(mlx, win, up_img, 0, 0);
	mlx_put_image_to_window(mlx, win, down_img, 0, 0);
	mlx_put_image_to_window(mlx, win, right_img, 64, 0);
	mlx_put_image_to_window(mlx, win, left_img, 0, 32);

	// printf("(%d, %d)\n", pos.x, pos.y);
	mlx_hook(win, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &pos);
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &press_key, &pos);
	mlx_loop(mlx);
	return (0);
}
