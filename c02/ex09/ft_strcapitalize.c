/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:40:53 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/08 21:36:39 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strlowcase2(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp >= 'A' && *tmp <= 'Z')
			*tmp += 'a' - 'A';
		tmp++;
	}
	return (str);
}

int	ch_str(char c)
{
	if (c >= 'a' && c <= 'b')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	else
		return (3);
}

char	*ft_strcapitalize(char *str)
{
	int	flag;

	str = ft_strlowcase2(str);
	flag = 0;
	while (*str)
	{
		if (flag == 0)
		{
			if (ch_str(*str) == 1)
				*str -= 32;
			flag = 1;
		}
		else
		{
			if (ch_str(*str) == 3)
				flag = 0;
		}
		str++;
	}
	return (str);
}
