#include	"get_next_line.h"
#include	<stdio.h>
#include	<fcntl.h>

int	statictest()
{
	static int a;

	if (a == 0)
		a = 4;
	a++;
	return (a);
}

char	*sss()
{
	static char	*a;

	if (a == 0)
		a = "abc";
	a = ft_strjoin(a, "def");
	return (a++);
}

void	point(char *test)	// 주소 복사해서 free해도 적용됨
{
	test++;
	// free(test);
	return ;
}
#define BUFFERSIZE 4
int main(void)
{
	int		check;
	int		fd = open("a.txt", O_RDONLY);
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
