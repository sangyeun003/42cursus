#include    <unistd.h>
#include    <stdlib.h>

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
	while (*s)
        if (*s == (char)c)
            return (s);
        else
            s++;
    return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)	// NULL 포함한 복사할 길이
{
	int i;
    int srcsize;

    i = 0;
    srcsize = ft_strlen(src);
    if (dstsize > 0)
    {
        while (i < dstsize - 1 && i < srcsize)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = 0;
    }
    return (dstsize);
}

char	*ft_strdup(const char *src)
{
	char    *result;

    result = malloc(ft_strlen(src) + 1);
    if (!result)
        return (NULL);
    ft_strlcpy(result, src, ft_strlen(src) + 1);
    return (result);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char    *result;
    int     len1;
    int     len2;

    if (!s1 || !s1)
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

char    *get_next_line(int fd)
{
    static  char    buf[BUFFER_SIZE + 1];
    char            *line;
    char            *newline;
    int             read_count;

    line = ft_strdup(buf);
    while (!ft_strchr(line, '\n') && (read_count = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_count] = 0;
        line = ft_strjoin(line, buf);
    }
    if (ft_strlen(line) == 0)
        return (NULL);
    newline = ft_strchr(line, '\n');
    if (newline == NULL)
    {
        ft_strlcpy(buf, "", BUFFER_SIZE + 1);
    }
    else
    {
        ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
        line[newline - line + 1] = 0;
    }
    return (line);
}