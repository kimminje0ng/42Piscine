/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:49:08 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/12 11:19:36 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2", 2);
			ft_putnbr(147483648);
		}
		else
		{
			write(1, "-", 1);
			ft_putnbr(nb * -1);
		}
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
