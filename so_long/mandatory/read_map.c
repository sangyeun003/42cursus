/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:03:20 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/24 22:36:02 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	open_map(int *fd, char *file_name)
{
	int	i;

	i = (int)ft_strlen(file_name) - 1;
	if (file_name[i--] != 'r')
		print_error("Invalid file format!");
	if (file_name[i--] != 'e')
		print_error("Invalid file format!");
	if (file_name[i--] != 'b')
		print_error("Invalid file format!");
	if (file_name[i--] != '.')
		print_error("Invalid file format!");
	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		print_error("File open failed!");
}

// 첫 줄 1인지 검사
void	read_map_first_line(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	game->map_str = ft_strdup_without_newline(line);
	if (!game->map_str)
		print_error("Malloc failed!");
	i = 0;
	while (game->map_str[i])
	{
		if (game->map_str[i] != '1')
			print_error("Invalid edge!");
		i++;
	}
	game->width = ft_strlen(game->map_str);
	game->height = 1;
}

// 각 줄 양 끝에 1 검사 && 맨 마지막 줄 1인지 검사 && 직사각형인지(길이가 game->width와 같은지) 검사
void	check_line(char *line, t_game *game)
{
	int	len;

	len = (int)ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		if (len - 1 != game->width || line[0] != '1' || line[len - 2] != '1')
			print_error("Invalid edge!");
	}
	else if (line[len - 1] != '\n')
	{
		if (len != game->width)
			print_error("Map is not rectangular!");
		while (--len > 0)
			if (line[len] != '1')
				print_error("Invalid edge!");
	}
	else
		print_error("Invalid Map!");
}

void	read_map(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	open_map(&fd, file_name);
	read_map_first_line(fd, game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_line(line, game);
		game->height++;
		temp = ft_strjoin_without_newline(game->map_str, line);
		if (!temp)
			print_error("Malloc failed!");
		free(game->map_str);
		game->map_str = ft_strdup(temp);
		if (!game->map_str)
			print_error("Malloc failed!");
		free(temp);
		free(line);
	}
	close(fd);
}
