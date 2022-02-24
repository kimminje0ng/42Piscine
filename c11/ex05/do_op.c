/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:49:50 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/24 15:26:09 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	calculator(char **av)
{
	int	(*fp[5])(char *, char *);
	int	result;

	fp[0] = &ft_add;
	fp[1] = &ft_sub;
	fp[2] = &ft_div;
	fp[3] = &ft_mul;
	fp[4] = &ft_rem;
	result = 0;
	if (!ft_strcmp(av[2], "+"))
		result = fp[0](av[1], av[3]);
	else if (!ft_strcmp(av[2], "-"))
		result = fp[1](av[1], av[3]);
	else if (!ft_strcmp(av[2], "/"))
		result = fp[2](av[1], av[3]);
	else if (!ft_strcmp(av[2], "*"))
		result = fp[3](av[1], av[3]);
	else if (!ft_strcmp(av[2], "%"))
		result = fp[4](av[1], av[3]);
	return (result);
}

int	main(int ac, char **av)
{
	int	result;

	if ((ac != 4) || (ft_check_zero(av[2], av[3])))
		return (0);
	result = 0;
	result = calculator(av);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
