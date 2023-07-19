/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:10:11 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/28 19:35:35 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/

int	ft_pstrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	n;

	n = ft_pstrlen(tab);
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
/*
#include	<unistd.h>
int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	ft_advanced_sort_string_tab(av, ft_strcmp);
	while (i < ac)
	{
		write(1, av[i], ft_strlen(av[i]));
		write(1, "\n", 1);
		i++;
	}
}
*/
/*
#include <stdio.h>
int str_len(char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}
int	ft_strcmp(char *s1, char *s2)
{
	return str_len(s1) - str_len(s2);
}
int	main(int argc, char** arr)
{
	ft_advanced_sort_string_tab(arr + 1, ft_strcmp);
	for(int i=1;i<argc;i++)
		printf("%s\n",arr[i]);
}
*/
