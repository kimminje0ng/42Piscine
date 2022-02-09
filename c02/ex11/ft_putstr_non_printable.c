/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:41:26 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/09 20:40:30 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_str_is_printable(char c)
{
	if (c <= 31 || c >= 127)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		n;

	hex = "0123456789abcdef";
	while (*str)
	{
		if (ft_str_is_printable(*str) == 0)
		{
			ft_putchar('\\');
			if (*str < 0)
			{
				n = (-128 - (*str)) * -1 + 128;
				ft_putchar(hex[n / 16]);
				ft_putchar(hex[n % 16]);
			}
			else
			{
				ft_putchar(hex[*str / 16]);
				ft_putchar(hex[*str % 16]);
			}
		}
		else
			ft_putchar(*str);
		str++;
	}
}
