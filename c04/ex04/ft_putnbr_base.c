/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:49:30 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/12 18:25:36 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ch_argv(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_num;
	unsigned int	new_nbr;

	base_num = ft_strlen(base);
	if (ch_argv(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		new_nbr = nbr * -1;
	}
	else
		new_nbr = nbr;
	if (new_nbr >= base_num)
		ft_putnbr_base(nbr / base_num, base);
	ft_putchar(base[nbr % base_num]);
}
