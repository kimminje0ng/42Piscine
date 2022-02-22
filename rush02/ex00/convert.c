/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:25:21 by minkyeki          #+#    #+#             */
/*   Updated: 2022/02/20 19:05:30 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

/* 1,234처럼 앞에 한 자리만 따로 처리해줘야하는 경우 */
int	print_1digit(char *num_in, char *buffer, int *digit_len, int *index)
{
	char	*digit_1;

	digit_1 = ft_itoa(num_in[*index] - '0'); 	// 남아있는 것 중에서 맨 앞 받아옴
	if (ft_check_dict_error(buffer, digit_1))	// 해당 숫자가 dict에 없으면 dict_error
	{
		free(digit_1);
		return (1);
	}
	*digit_len -= 1;	// 남은 읽을 숫자 갯수 -1
	*index += 1;		// index 직접 +1
	ft_write_number_power(*digit_len, buffer);
	free(digit_1);
	return (0);
}

/* 12,345처럼 앞에 두 자리만 따로 처리해줘야하는 경우 */
int	print_2digit(char *num_in, char *buffer, int *digit_len, int *index)
{
	char	*digit_10;
	int		tmp;

	tmp = (num_in[*index] - '0') * 10 + num_in[*index + 1] - '0';
	digit_10 = ft_itoa(tmp);
	if (ft_write_nbr_2digits(digit_10, buffer))
	{
		free(digit_10);
		return (1);
	}
	*index += 2;
	*digit_len -= 2;
	ft_write_number_power(*digit_len, buffer);
	free(digit_10);
	return (0);
}

/* 123,456처럼 3개 묶어서 처리해줘야하는 경우 */
int	print_3digit(char *num_in, char *buffer, int *digit_len, int *index)
{
	char	*digit_10;
	char	*digit_1;
	int		tmp;

	digit_1 = ft_itoa(num_in[*index] - '0');
	if (ft_print_hundred_point(num_in, buffer, digit_1, index))
		return (1);
	tmp = (num_in[*index + 1] - '0') * 10 + (num_in[*index + 2] - '0');
	digit_10 = ft_itoa(tmp);
	if (num_in[*index + 1] != '0' || num_in[*index + 2] != '0')  // 300, 400 처리
	{
		write(1, " ", 1);
		ft_write_nbr_2digits(digit_10, buffer);
	}
	*digit_len -= 3;
	// 300,000이면 뒤에 따로 처리 안해줘야함
	if ((*digit_len >= 3) && (num_in[*index] != '0' || num_in[*index \
			+ 1] != '0' || num_in[*index + 2] != '0'))
		ft_write_number_power(*digit_len, buffer);
	*index += 3;
	free(digit_1);
	free(digit_10);
	return (0);
}

int	ft_print_hundred_point(char *num_in, char *buffer, char *digit_1,
		int *index)
{
	if (num_in[*index] != '0')  // 1,032 이렇게 중간에 0들어간거 처리
	{
		if (*index != 0)  // 맨 앞은 이미 앞에서 띄어쓰기 해줬으니까 패스
			write(1, " ", 1);
		if (ft_check_dict_error(buffer, digit_1)) // one hundred에서 one 출력
		{
			free(digit_1);
			return (1);
		}
		write(1, " ", 1);
		if (ft_check_dict_error(buffer, "100"))  // one hundred에서 hunred 출력
		{
			free(digit_1);
			return (1);
		}
	}
	return (0);
}

/* 자리수(,앞에 0/1/2개인지) 확인해서 print_*digit으로 넘겨주는 함수 (에러:1, 성공:0) */
int	ft_convert_full_nbr(char *num_in, char *buffer)
{
	int	digit_len;	// 들어온 숫자의 길이
	int	i;			// thousand 같이 3자리씩 끊었을 때 쉼표(,)값 출력하기 위해 사용하는 변수

	i = 0;
	digit_len = ft_strlen(num_in);
	while (digit_len > 0)
	{
		if (digit_len > 1 && num_in[0] == '0')	// 0으로 시작하는 숫자(03, 002) 에러처리
		{
			write(1, "Dict Error\n", 11);
			return (1);
		}
		// 1,234에서 맨 앞자리(1) 출력. print_*digit의 dict error 처리
		if ((digit_len % 3 == 1) && (print_1digit(num_in, buffer, &digit_len, \
					&i)))
			return (1);
		// 12,345에서 앞 두자리(12) 출력
		else if ((digit_len % 3 == 2) && (print_2digit(num_in, buffer, \
						&digit_len, &i)))
			return (1);
		// 123,456에서 123을 한 번에 출력
		else if ((digit_len % 3 == 0) && (print_3digit(num_in, buffer, \
						&digit_len, &i)))
			return (1);
	}
	return (0);
}
