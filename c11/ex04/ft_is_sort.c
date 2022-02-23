/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:49:29 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/23 20:10:07 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	cnt1;
	int	cnt2;

	i = 0;
	cnt1 = 0;
	cnt2 = 0;
	if (length <= 1)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			cnt1++;
		if (f(tab[i], tab[i + 1]) >= 0)
			cnt2++;
		i++;
	}
	if (cnt1 == length - 1 || cnt2 == length - 1)
		return (1);
	else
		return (0);
}
