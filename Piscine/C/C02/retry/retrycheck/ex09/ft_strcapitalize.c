/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyepa <sangyepa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:30:22 by sangyepa          #+#    #+#             */
/*   Updated: 2023/02/15 16:23:24 by sangyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_word_cap(char *str, int *i);
char	*ft_strcapitalize(char *str);

char	*ft_word_cap(char *str, int *i)
{
	if (str[*i + 1] >= 'a' && str[*i + 1] <= 'z')
	{
		str[*i + 1] -= 'a' - 'A';
		(*i)++;
	}
	else if (str[*i + 1] >= 'A' && str[*i + 1] <= 'Z')
		(*i)++;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] -= 'a' - 'A';
		if (str[i] <= 47 || (str[i] >= 58 && str[i] <= 64))
			ft_word_cap(str, &i);
		else if (str[i] >= 91 && str[i] <= 96)
			ft_word_cap(str, &i);
		else if (str[i] >= 123)
			ft_word_cap(str, &i);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}
