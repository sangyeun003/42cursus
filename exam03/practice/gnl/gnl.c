#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#ifndef BUFFER_SIZE
# define	BUFFER_SIZE	1
#endif

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)	// NULL 포함한 복사할 길이
{
	int	srcsize;
	int	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = NULL;
	}
	return (srcsize);
}

char	*ft_strdup(const char *src)
{
	char	*s;
	size_t	len;

	len = ft_strlen(src);
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, src, len + 1);
	return (s);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			count_read;

	line = ft_strdup(buf);
	// printf("line len: %d\n", ft_strlen(line));
	while (!ft_strchr(line, '\n') && (count_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[count_read] = NULL;
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (NULL);
	newline = ft_strchr(line, '\n');
	if (!newline)
	{
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	else
	{
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
		line[newline - line + 1] = NULL;
	}
	return (line);
}

#include	<stdio.h>
#include	<fcntl.h>

#define BUFFERSIZE 4
int main(void)
{
	int		check;
	int		fd = open("a.txt", O_RDONLY);
	// int		fd = 2;
	char	*buf;
	// char	test[4] = "abc";
	// char	*test2 = test;
	// *test2 = 48;
	// printf("%s\n", test2);
	// printf("%s\n", test);
	// point(test);
	// printf("%s\n", test);

	// buf = malloc((BUFFERSIZE + 1) * sizeof(char));
	// check = read(fd, buf, BUFFERSIZE);
	// buf[BUFFERSIZE] = 0;
	// printf("%s\n", buf);
	// buf = ft_strjoin(buf, "123");
	// printf("%s\n", buf);

	// free(buf);
	// printf("%s\n", buf);

	// buf = 0;
	// printf("%s\n", buf);

	// check = read(fd, buf, BUFFERSIZE);
	// buf[BUFFERSIZE] = 0;
	// printf("%s", buf);
	// int i = 1;
	// while (1)
	// {
	// 	buf = get_next_line(fd);
	// 	if (buf)
	// 		printf("%d. %s\n", i++, buf);
	// 	else
	// 		break ;
	// }
	printf("1. %s\n", get_next_line(fd));
	printf("2. %s\n", get_next_line(fd));
	printf("3. %s\n", get_next_line(fd));
	printf("4. %s\n", get_next_line(fd));
	printf("5. %s\n", get_next_line(fd));

	// system("leaks a.out");
	
	// printf("%s", get_next_line(fd));
	// printf("%d\n", read(fd, buf, 20));
	// printf("%d\n", read(fd, buf, 3));
	// printf("%d\n", statictest());
	// printf("%d\n", statictest());
	// printf("%d\n", statictest());

	// printf("%s\n", sss());
	// printf("%s\n", sss());
	// printf("%s\n", sss());
}
