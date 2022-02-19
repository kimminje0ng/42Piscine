/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:10:30 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/19 16:26:16 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = '\0';
	return (dest);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*tmp_str;
	unsigned int	strs_len;
	int				i;

	i = 1;
	strs_len = ft_strlen(strs[0]);
	while (i < size)
	{
		strs_len += ft_strlen(sep) + ft_strlen(strs[i]);
		i++;
	}
	tmp_str = (char *)malloc(sizeof(char) * (strs_len + 1));
	*tmp_str = '\0';
	i = 0;
	while (i < size)
	{
		tmp_str = ft_strcat(tmp_str, strs[i]);
		if (i != size - 1)
			tmp_str = ft_strcat(tmp_str, sep);
		i++;
	}
	return (tmp_str);
}
