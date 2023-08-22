#include	<unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				while (argv[1][i] == ' ' || argv[1][i] == '\t')
					i++;
				if (argv[1][i])
					write(1, " ", 1);
			}
			if (!argv[1][i])
				break ;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
