/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:05:46 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/24 20:32:00 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	check_in_sep(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	num_of_word(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && check_in_sep(str[i], charset))
			i++;
		if (str[i] && !check_in_sep(str[i], charset))
			size++;
		while (str[i] && !check_in_sep(str[i], charset))
			i++;
	}
	return (size);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str && check_in_sep(*str, charset))
		str++;
	while (*(str + len) && !check_in_sep(*(str + len), charset))
		len++;
	return (len);
}

void	alloc_word(char **result, char *str, char *charset, int size)
{
	int	i;
	int	j;
	int	wordlen;

	i = 0;
	j = 0;
	while (i < size)
	{
		wordlen = word_len(str, charset);
		result[i] = (char *)malloc((wordlen + 1) * sizeof(char));
		while (*str && check_in_sep(*str, charset))
			str++;
		while (j < wordlen)
		{
			result[i][j] = *(str++);
			j++;
		}
		result[i][j] = '\0';
		j = 0;
		i++;
	}
	result[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		size;
	int		i;

	i = 0;
	size = num_of_word(str, charset);
	result = (char **)malloc((size + 1) * sizeof(char *));
	alloc_word(result, str, charset, size);
	return (result);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define RESET  "\033[0m"
#define PASS(res) res == 0 ? printf( GREEN " (\xE2\x9C\x93)" RESET ) :\
printf( RED " (x)"  RESET );
#define RET(res, ret) res == 0 ?\
printf( GREEN "%s\n\n" RESET, ret) : printf( RED "%s\n\n" RESET, ret);
int main()
{
	int chk;
	int idx;
	char *s[13] = { \
		"            ",\
		"        ",\
		"kagjzVMN",\
		"rWG9pl",\
		"y9v8nSCKhrtU4rrCm7UbsWhcEVmrGFKcKHB7WIM",\
		"KndMqkXO3HSS454eino\fvxKDkr1Z\tZFkb8tmf0C5",\
		"8ERXDYw28Q UJmNnHxCYNuXVvxJ58ELXRgaHaEH",\
		"q10ESS3P8ezU kJ5koNzyXVK0\tomNJRjinj7i",\
		"hlTzv9FNtsqw1fKBiBrVCwim    wSoLEgBPI5jKWD",\
		"MDD4cEf1PcAriHHW3BaQmN0lgIeVfLj6UHD9MCET",\
		" gh ",\
		" gh ",\
		"XDhhm\tKVDOoAtPM76YdXMLiYhQ8y3Bqvr3pytnKT1EA" };

	char *cs[13] = { \
		" ",\
		" ",\
		"kagjzVMN",\
		"rWG9pl",\
		"o0Fty7",\
		"egiHXjOn",\
		"hAF",\
		"SpRi \fkfN",\
		"6BmSx",\
		"4rkITxy",\
		" gh",\
		" ",\
		"" };
	
	char *ans[13][50] = { { 0 }, { 0 }, { 0 }, { 0 },\
		{ "9v8nSCKhr", "U4rrCm", "UbsWhcEVmrG", "KcKHB", "WIM", 0 },\
		{ "K", "dMqk", "3", "SS454", "o\fvxKDkr1Z\tZFkb8tmf0C5", 0 },\
		{ "8ERXDYw28Q UJmNnHxCYNuXVvxJ58ELXRgaHaEH", 0 },\
		{ "q10E", "3P8ezU", "J5", "o", "zyXVK0\tom", "J", "j", "nj7", 0 },\
		{ "hlTzv9FNtsqw1fK", "i", "rVCwi", "    w", "oLEg", "PI5jKWD", 0 },\
		{ "MDD", "cEf1PcA", "iHHW3BaQmN0lg", "eVfLj6UHD9MCE", 0 },\
		{ 0 },\
		{ "gh", 0 },\
		{ "XDhhm\tKVDOoAtPM76YdXMLiYhQ8y3Bqvr3pytnKT1EA", 0 } };

	char **uo[13];

	for (int i = 0; i < 13; i++)
		uo[i] = ft_split(s[i], cs[i]);

	for (int i = 0; i < 13; i++)
	{
		idx = -1;
		chk = 0;
		printf(YELLOW "\nTEST%d string  is:" BLUE " \"%s\"" RESET, i + 1, s[i]);
		printf(YELLOW "\nTEST%d charset is:" BLUE " \"%s\"\n" RESET, i + 1, cs[i]);
		printf(YELLOW "\nTEST RESULT :"RESET);

		while (ans[i][++idx] != 0)
			chk += !!strcmp(ans[i][idx], uo[i][idx]);
		PASS(chk)
        printf("\n" );
        printf("-------------------------------\n");
		idx = -1;
		printf(YELLOW "tab start\n" RESET);
		while (ans[i][++idx] != 0)
		{
			printf("answer[%d] : %s\nusrout[%d] : ", idx, ans[i][idx], idx);
			RET(strcmp(ans[i][idx], uo[i][idx]), uo[i][idx]);
		}
		printf(YELLOW "tab end\n" RESET);
        printf("-------------------------------\n\n");

        usleep(500000);
	}

}
*/
