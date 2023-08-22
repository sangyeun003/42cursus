#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

int	wordlen(char *str)
{
	int	len;

	while (*str == ' ' || *str == '\t')
		str++;
	len = 0;
	while (!(*str == ' ' || *str == '\t') && *str)
	{
		str++;
		len++;
	}
	// printf("1\n");
	return (len);
}

int	num_of_word(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (!(*str == ' ' || *str == '\t') && *str)
			result++;
		while (!(*str == ' ' || *str == '\t') && *str)
			str++;
	}
	// printf("1\n");
	return (result);
}

char	**alloc_word(char *str, int numofword)
{
	int		i;
	char	**result;

	// printf("1\n");
	result = (char **)malloc((numofword + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	// printf("1\n");
	while (i < numofword)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		result[i] = (char *)malloc((wordlen(str) + 1) * sizeof(char));
		if (!result[i])
		{
			while (i >= 0)
				free(result[i--]);
			return (0);
		}
		strncpy(result[i], str, wordlen(str));
		// printf("%s\n", result[i]);
		str += wordlen(str);
		i++;
	}
	result[numofword] = 0;
	// printf("1\n");
	return (result);
}

char	**ft_split(char *str)
{
	char	**result;

	// printf("1\n");
	result = alloc_word(str, num_of_word(str));
	// printf("1\n");
	return (result);
}

// int	wordlen(char *str)
// {
// 	int	len;
// 	int	i = 0;

// 	len = 0;
// 	while ((*str >= 9 && *str < 13) || *str == 32)
// 		str++;
// 	while (!((str[i] >= 9 && str[i] < 13) || str[i] == 32) && str[i++])
// 		len++;
// 	return (len);
// }

// char	**ft_split(char *str)
// {
// 	int		num_of_word;
// 	int		word_len;
// 	int		i;
// 	int		j;
// 	char	**result;

// 	i = 0;
// 	num_of_word = 0;
// 	while (str[i])
// 	{
// 		while ((str[i] >= 9 && str[i] < 13) || str[i] == 32)
// 			i++;
// 		if (str[i])
// 			num_of_word++;
// 		while (!((str[i] >= 9 && str[i] < 13) || str[i] == 32) && str[i])
// 			i++;
// 	}
// 	result = (char **)malloc(num_of_word * (sizeof(char *) + 1));
// 	if (!result)
// 		return (0);
// 	i = 0;
// 	while (i < num_of_word)
// 	{
// 		result[i] = (char *)malloc((wordlen(str) + 1) * sizeof(char));
// 		if (!result[i])
// 			return (0);
// 		while ((*str >= 9 && *str < 13) || *str == 32)
// 			str++;
// 		j = 0;
// 		while (j < word_len)
// 			result[i][j++] = *str++;
// 		result[i][j] = 0;
// 		i++;
// 	}
// 	result[i] = 0;
// 	return (result);
// }

int	main(int argc, char *argv[])
{
	// printf("1\n");
	char	**result = ft_split(argv[1]);
	int		i = 0;
	while (result[i])
		printf("%s ", result[i++]);
	return (0);
}