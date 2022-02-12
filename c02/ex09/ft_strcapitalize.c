/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:40:53 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/12 17:02:34 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
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
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	else
		return (3);
}

char	*ft_strcapitalize(char *str)
{
	int		flag;
	char	*tmp;

	flag = 0;
	tmp = ft_strlowcase(str);
	while (*tmp)
	{
		if (flag == 0)
		{
			if (ch_str(*tmp) == 1)
			{
				*tmp -= 32;
				flag = 1;
			}
			else if (ch_str(*tmp) == 3)
				flag = 0;
			else
				flag = 1;
		}
		else if (flag != 0 && ch_str(*tmp) == 3)
			flag = 0;
		tmp++;
	}
	return (str);
}
