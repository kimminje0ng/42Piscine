/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:10:39 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/19 16:26:47 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		match_atoi(char c, char *base);
int		nbr_len(long long nbr, int base_len);

int	check_base(char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	minus_flag;
	int	value;

	minus_flag = 1;
	if (check_base(base) == 0)
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

char	*ft_itoa_base(int num, char *base)
{
	long long	tmp_num;
	char		*result;
	int			nbr_size;

	tmp_num = num;
	if (tmp_num == 0)
	{
		result = (char *)malloc(sizeof(char) * 2);
		result[0] = base[0];
		result[1] = 0;
		return (result);
	}
	nbr_size = nbr_len(tmp_num, ft_strlen(base));
	if (tmp_num < 0)
		tmp_num *= -1;
	result = (char *)malloc(sizeof(char) * (nbr_size + 1));
	result[nbr_size] = 0;
	while (tmp_num != 0)
	{
		result[--nbr_size] = base[tmp_num % ft_strlen(base)];
		tmp_num /= ft_strlen(base);
	}
	if (num < 0)
		result[0] = '-';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_num;
	char	*result;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	decimal_num = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(decimal_num, base_to);
	return (result);
}
