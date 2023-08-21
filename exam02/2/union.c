#include	<unistd.h>

int	check(char *str, char c, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (0);
		j++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
		len = i;
		i = 0;
		while (argv[2][i])
		{
			if (check(argv[1], argv[2][i], len) && check(argv[2], argv[2][i], i))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
