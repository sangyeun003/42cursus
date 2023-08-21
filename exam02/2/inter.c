#include	<unistd.h>

int	check_double(char *str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (str[j] == str[i])
			return (0);
		j++;
	}
	return (1);
}

int	check_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (check_double(argv[1], i) && check_in(argv[1][i], argv[2]))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
