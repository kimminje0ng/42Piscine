/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:56 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/21 14:03:29 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset) == 1)
			str++;
		if (*str && is_sep(*str, charset) == 0)
		{
			cnt++;
			while (*str && is_sep(*str, charset) == 0)
				str++;
		}
	}
	return (cnt);
}

char	*put_word(char *str, char *charset)
{
	char	*word;
	char	*tmp;
	int		i;

	i = 0;
	tmp = str;
	while (str[i] && is_sep(str[i], charset) == 0)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && is_sep(str[i], charset) == 0)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset) == 1)
			str++;
		if (*str && is_sep(*str, charset) == 0)
		{
			res[i++] = put_word(str, charset);
			while (*str && is_sep(*str, charset) == 0)
				str++;
		}
	}
	res[i] = 0;
	return (res);
}
