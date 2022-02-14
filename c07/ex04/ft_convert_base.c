/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:10:39 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/14 21:55:00 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//check
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

//check
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// check
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

// check
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

// no check
char	*ft_itoa_base(int num, char *base)
{
	num = 0;
}

// total function
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_num;
	char	*result;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	/* 문자 -> 10진수 변환 */
	decimal_num = ft_atoi_base(nbr, base_from);
	/* 10진수 -> 문자 변환 */
	result = ft_itoa_base(decimal_num, base_to);
	return (result);
}

/*hyewon code*/
char	*ft_itoa_base(int nbr, char *base)
{
	long long	tmp;
	char		*ret;
	int			size;

	if (nbr == 0)
	{
		ret = (char *)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = nbr;
	size = nbr_size(tmp, ft_strlen(base));
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % ft_strlen(base)];
		tmp /= ft_strlen(base);
	}
	if (nbr < 0)
		ret[0] = '-';
	return (ret);
}

int	nbr_size(long long nbr, int base_len)
{
	int	res_size;

	if (!nbr)
		return (1);
	res_size = 0;
	if (nbr < 0)
		++res_size;
	while (nbr)
	{
		nbr /= base_len;
		++res_size;
	}
	return (res_size);
}
