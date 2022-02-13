/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:52:20 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/12 21:44:27 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_params(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		while (*av[i])
		{
			write(1, av[i], 1);
			av[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			j = i + 1;
			while (j < ac)
			{
				if (ft_strcmp(av[i], av[j]) > 0)
				{
					tmp = av[i];
					av[i] = av[j];
					av[j] = tmp;
				}
				j++;
			}
			i++;
		}
		print_params(ac, av);
	}
	return (0);
}
