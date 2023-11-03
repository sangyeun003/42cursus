/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:03:20 by sangyepa          #+#    #+#             */
/*   Updated: 2023/11/03 15:19:20 by sangyepa         ###   ########.fr       */
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
	if (*fd < 0)
		print_error("File open failed!");
}

void	check_and_read_first_line(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		print_error("Malloc failed!");
	game->map_str = ft_strdup_without_newline(line);
	free(line);
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

void	check_last_line(t_game *game)
{
	int	i;

	i = (int)ft_strlen(game->map_str) - game->width;
	while (game->map_str[i])
	{
		if (game->map_str[i] != '1')
			print_error("Invalid edge!");
		i++;
	}
}

void	check_line(char *line, t_game *game)
{
	char	*just_line;
	int		len;

	just_line = ft_strdup_without_newline(line);
	if (!just_line)
		print_error("Malloc failed!");
	len = (int)ft_strlen(just_line);
	if (len != game->width)
		print_error("Map is not rectangular!");
	if (just_line[0] != '1' || just_line[len - 1] != '1')
		print_error("Invalid edge!");
	free(just_line);
}

void	read_map(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	open_map(&fd, file_name);
	check_and_read_first_line(fd, game);
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
	check_last_line(game);
}
