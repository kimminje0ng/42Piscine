/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingypar <mingypar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:05:30 by mingypar          #+#    #+#             */
/*   Updated: 2022/02/05 17:07:47 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int idx_x, int idx_y, int x, int y)
{
	if (idx_x == 1 && idx_y == 1)
		ft_putchar('/');
	else if ((idx_x == x && idx_y == 1) || (idx_x == 1 && idx_y == y))
		ft_putchar('\\');
	else if (idx_x == x && idx_y == y)
		ft_putchar('/');
	else if ((idx_x == 1) || (idx_x == x) || (idx_y == 1) || (idx_y == y))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	idx_x;
	int	idx_y;

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
