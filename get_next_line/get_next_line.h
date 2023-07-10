/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:43:27 by sangyepa          #+#    #+#             */
/*   Updated: 2023/07/10 21:22:44 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include	<unistd.h>
# include	<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// # ifndef OPEN_MAX
// #  define OPEN_MAX 8192
// # endif

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif