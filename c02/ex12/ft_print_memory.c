/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:41:38 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/09 21:05:33 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	p_hex(char *str, char *hex)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!*str)
		{
			write(1, " ", 1);
			break ;
		}
		write(1, &hex[*str / 16], 1);
		write(1, &hex[*str % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		str++;
		i++;
	}
	while (i++ < 16)
	{
		if (i % 2 == 1)
			write(1, " ", 1);
		write(1, "  ", 2);
	}
}

void	p_str(char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!*str)
			break ;
		if (*str <= 31 || *str >= 127)
			write(1, ".", 1);
		else
			write(1, str, 1);
		str++;
		i++;
	}
	write(1, "\n", 1);
}

void	addr2hex(unsigned long long addr, unsigned int i, char *hex)
{
	if (addr != 0)
	{
		addr2hex(addr / 16, i + 1, hex);
		write(1, &hex[addr % 16], 1);
	}
	else
	{
		while (i < 16)
		{
			write(1, "0", 1);
			i++;
		}
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*tmp;
	char			*hex;

	tmp = (char *)addr;
	hex = "0123456789abcdef";
	i = 0;
	while (*tmp != 0 && size > i)
	{
		addr2hex((unsigned long long)tmp, 0, hex);
		write(1, ": ", 2);
		p_hex(tmp, hex);
		p_str(tmp);
		tmp += 16;
		i += 16;
	}
}
