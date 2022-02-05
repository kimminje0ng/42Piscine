/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:43:36 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/05 19:30:57 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_finish;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	combination(int *arr, int n, int index, int number)
{
	int	i;

	if (n == 0)
	{
		i = 0;
		if (g_finish == 1)
			write(1, ", ", 2);
		while (i < index)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
		g_finish = 1;
	}
	else
	{
		if (number <= 9)
		{
			arr[index] = number;
			combination(arr, n - 1, index + 1, number + 1);
			combination(arr, n, index, number + 1);
		}
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	g_finish = 0;
	combination(arr, n, 0, 0);
}
