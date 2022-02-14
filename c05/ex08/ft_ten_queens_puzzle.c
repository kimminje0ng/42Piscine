/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:46:32 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/14 12:06:08 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	print_case(int arr[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar2(arr[i] + '0');
		i++;
	}
	ft_putchar2('\n');
}

int	check_set(int arr[10], int cur_row)
{
	int	i;

	i = 0;
	while (i < cur_row)
	{
		if (arr[i] == arr[cur_row] || (cur_row - i) == (arr[i] - arr[cur_row]))
			return (0);
		if ((cur_row - i) == (arr[cur_row] - arr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	set_queens(int arr[10], int row, int *count)
{
	int	i;

	if (row == 10)
	{
		*count = *count + 1;
		print_case(arr);
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			arr[row] = i;
			if (check_set(arr, row) != 0)
				set_queens(arr, row + 1, count);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int	count;

	i = 0;
	set_queens(arr, 0, &count);
	return (count);
}
