/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:27 by sangyepa          #+#    #+#             */
/*   Updated: 2023/09/11 16:17:37 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# include	<unistd.h>
# include	<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		ft_initial_setting(int fd, char **backup, char **buf);
int		ft_make_return_value(char **backup, char **line);
int		ft_read(int fd, char **backup, char **buf, int read_size);
int		ft_refine_backup(char **backup, char **line);
void	ft_free_one_str(char **str);
void	ft_free_two_str(char **str1, char **str2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif