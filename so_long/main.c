/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:33:07 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/15 22:03:45 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -lmlx -framework OpenGl -framework AppKit -Imlx main.c

#include	"so_long.h"


  typedef struct s_key{
  	int		x;
  	int		y;
  }				t_key;
    
  // 구조체 멤버 변수 초기화
  void	key_init(t_key *key)
  {
  	key->x = 0;
  	key->y = 0;
  }
    
  // 키가 눌렸을 때
  int	key_press(int keycode, t_key *key)
  {
  	if (keycode == W_KEY)
  		key->y++;
  	else if (keycode == S_KEY)
  		key->y--;
  	else if (keycode == A_KEY)
  		key->x--;
  	else if (keycode == D_KEY)
  		key->x++;
  	else if (keycode == ESC_KEY)
  		exit(0);
  	else
  		return (0);
  	printf("(%d, %d)\n", key->x, key->y);
  	return (0);
  }
    
  int	close_window(void)
  {
  	exit(0);
  	// return (0);
  }
    
  int	main(void)
  {
  	void		*mlx;
  	void		*win;
  	t_key   key;
    
  	mlx = mlx_init(); // mlx포인터 생성
  	win = mlx_new_window(mlx, 500, 500, "key test"); // 윈도우 띄우기
  	key_init(&key); // 구조체 값 초기설정
  	printf("(%d, %d)\n", key.x, key.y);
  	mlx_hook(win, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &key);	// 마우스로 창 닫을 때 종료되게 하는듯
  	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &key);
  	mlx_loop(mlx);
  }
// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	t_pos	pos;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 1920, 1080, "key_test");

// 	pos_init(&pos);

// 	printf("(%d, %d)\n", pos.x, pos.y);
// 	mlx_hook(win, X_EVENT_DESTROY_NOTIFY, 0, &close_window, &pos);
// 	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &press_key, &pos);

// 	mlx_loop(mlx);
// }


// int	main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	void	*img_ptr;
// 	t_pos	pos;
// 	int		bits_per_pixel;
// 	int		size_line;
// 	int		endian;
// 	char	*img_addr;

// 	pos.x = 0;
// 	pos.y = 0;
// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "jibang");
// 	mlx_hook(win_ptr, KEY_RELEASE, 0, &key_press, &pos);
// 	mlx_loop(mlx_ptr);

// 	return (0);
// }
