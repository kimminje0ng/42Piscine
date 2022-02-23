#include "mylib.h"

int	ft_check_zero(char *op, char *num)
{
	if (!ft_strcmp(op, "/") && !ft_strcmp(num, "0"))
	{
		write(1, "Stop : division by zero\n", 25);
		return (1);
	}
	else if (!ft_strcmp(op, "%") && !ft_strcmp(num, "0"))
	{
		write(1, "Stop : modulo by zero\n", 23);
		return (1);
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	long long	result;
	int			minus_flag;

	result = 0;
	minus_flag = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_flag *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * minus_flag);
}

void	tr_itoa(char *str, int num, int idx)
{
	str[idx--] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return ;
	}
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[idx--] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int num)
{
	long long	tmp_num;
	char		*result;
	int			nbr_size;

	tmp_num = num;
	if (tmp_num == 0)
	{
		result = (char *)malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	nbr_size = ft_intlen(tmp_num);
	if (tmp_num < 0)
		tmp_num *= -1;
	result = (char *)malloc(sizeof(char) * (nbr_size + 1));
	result[nbr_size] = '\0';
	while (tmp_num != 0)
	{
		result[--nbr_size] = (tmp_num % 10) + '0';
		tmp_num /= 10;
	}
	if (num < 0)
		result[0] = '-';
	return (result);
}
