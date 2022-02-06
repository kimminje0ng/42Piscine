/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:34:46 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/05 17:11:58 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int idx_x, int idx_y, int x, int y)
{
	if ((idx_x == 1 && idx_y == 1) || (idx_x == x && idx_y == 1))
	{
		ft_putchar('A');
	}
	else if ((idx_y == y && idx_x == 1) || (idx_y == y && idx_x == x))
	{
		ft_putchar('C');
	}
	else if (idx_x == 1 || idx_x == x)
	{
		ft_putchar('B');
	}
	else if (idx_y == 1 || idx_y == y)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int		idx_x;
	int		idx_y;

	if (x <= 0 || y <= 0)
	{
		return ;
	}	
	idx_y = 1;
	while (idx_y <= y)
	{
		idx_x = 1;
		while (idx_x <= x)
		{
			print(idx_x, idx_y, x, y);
			idx_x++;
		}
		idx_y++;
		ft_putchar('\n');
	}
}
