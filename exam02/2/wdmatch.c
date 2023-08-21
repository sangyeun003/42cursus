#include	<unistd.h>

int	check(char *str1, char *str2)
{
	int	ind1;
	int	ind2;

	ind1 = 0;
	ind2 = 0;
	while (str1[ind1])
	{
		while (str2[ind2])
		{
			if (str1[ind1] == str2[ind2])
				break ;
			ind2++;
		}
		if (str2[ind2] == 0)
			return (0);
		ind1++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3 && check(argv[1], argv[2]))
	{
		i = 0;
		while (argv[1][i])
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
}