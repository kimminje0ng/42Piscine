/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:49:48 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/12 15:25:07 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ch_argv(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	match_atoi(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	minus_flag;
	int	value;

	minus_flag = 1;
	if (ch_argv(base) == 0)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_flag *= -1;
		str++;
	}
	result = 0;
	value = match_atoi(*str, base);
	while (*str && value >= 0)
	{
		result = result * ft_strlen(base) + value;
		str++;
		value = match_atoi(*str, base);
	}
	return (result * minus_flag);
}
