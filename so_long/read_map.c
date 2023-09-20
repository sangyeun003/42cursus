/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:03:20 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/20 18:37:58 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	read_map(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	game->map_str = ft_strdup_without_newline(line);
	game->width = ft_strlen(game->map_str);
	game->height = 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->height++;
		temp = ft_strjoin_without_newline(game->map_str, line);
		if (!temp)
			exit(1);
		free(game->map_str);
		game->map_str = ft_strdup(temp);
		if (!game->map_str)
			exit(1);
		free(temp);
		free(line);
	}
	close(fd);
}
