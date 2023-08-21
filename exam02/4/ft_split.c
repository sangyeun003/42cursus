#include	<stdlib.h>
#include	<stdio.h>

int	wordlen(char *str)
{
	int	len;
	int	i = 0;

	len = 0;
	while ((*str >= 9 && *str < 13) || *str == 32)
		str++;
	while (!((str[i] >= 9 && str[i] < 13) || str[i] == 32) && str[i++])
		len++;
	return (len);
}

char	**ft_split(char *str)
{
	int		num_of_word;
	int		word_len;
	int		i;
	int		j;
	char	**result;

	i = 0;
	num_of_word = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] < 13) || str[i] == 32)
			i++;
		if (str[i])
			num_of_word++;
		while (!((str[i] >= 9 && str[i] < 13) || str[i] == 32) && str[i])
			i++;
	}
	result = (char **)malloc(num_of_word * (sizeof(char *) + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < num_of_word)
	{
		result[i] = (char *)malloc((wordlen(str) + 1) * sizeof(char));
		if (!result[i])
			return (0);
		while ((*str >= 9 && *str < 13) || *str == 32)
			str++;
		j = 0;
		while (j < word_len)
			result[i][j++] = *str++;
		result[i][j] = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

int	main(int argc, char *argv[])
{
	char	**result = ft_split(argv[1]);
	int		i = 0;
	while (result[i])
		printf("%s ", result[i++]);
	return (0);
}