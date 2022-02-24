/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:10 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/24 15:25:41 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	ft_add(char *a, char *b)
{
	return (ft_atoi(a) + ft_atoi(b));
}

int	ft_sub(char *a, char *b)
{
	return (ft_atoi(a) - ft_atoi(b));
}

int	ft_div(char *a, char *b)
{
	return (ft_atoi(a) / ft_atoi(b));
}

int	ft_mul(char *a, char *b)
{
	return (ft_atoi(a) * ft_atoi(b));
}

int	ft_rem(char *a, char *b)
{
	return (ft_atoi(a) % ft_atoi(b));
}
