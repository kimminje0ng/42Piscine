/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:45:33 by djeong            #+#    #+#             */
/*   Updated: 2022/02/20 19:05:43 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/* 입력한 정수가 유효한 지를 판단하는 함수 (에러:0, 정상:1) */
int	ft_check_number(char *nbr)
{
	int	i;
	int	nbr_size;

	i = 0;
	nbr_size = ft_strlen(nbr);
	if (nbr_size > 39)	// 최대 범위의 수를 넘으면 에러 (영어로 표현 못함)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (nbr[i])		// 숫자가 아닌 게 있으면 에러
	{
		if (nbr[i] < '0' || nbr[i] > '9')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}


/* 메인 알골(ft_convert_full_nbr) 실행 결과값으로 dict error 출력하는 함수 */
void	print_dict_error(char *str, char *buffer)
{
	if (ft_convert_full_nbr(str, buffer))	// 사전에서 못찾으면(1) dict error 출력
		write(2, "dict Error\n", 11);
}


/* to_find가 dictionary에 있는 지를 확인하는 함수 */
int	ft_check_dict_error(char *buffer, char *to_find)
{
	int		size;
	char	*tmp;
	char	*start;

	start = ft_strstr(buffer, to_find);
	size = 0;
	while (start[size] >= '0' && start[size] <= '9')
		size++;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	tmp[size] = '\0';
	size = 0;
	while (start[size] >= '0' && start[size] <= '9')
	{
		tmp[size] = start[size];
		size++;
	}
	if (ft_strcmp(to_find, tmp) != 0)
	{
		free(tmp);
		return (1);
	}
	ft_write_nbr_into_ltrs(start, buffer);
	free(tmp);
	return (0);
}
