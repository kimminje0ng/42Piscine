/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:41:52 by djeong            #+#    #+#             */
/*   Updated: 2022/02/21 19:16:59 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	main(int argc, char **argv)
{
	char	*buffer;

	if (argc > 3 || argc == 1)  // 인자 에러 처리
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)  // numbers.dict 사용해서 정수 처리
	{
		if (ft_check_number(argv[1]) == 0)  // 입력한 정수가 유효하지 않으면 종료
			return (0);
		buffer = ft_open_read();			// numbers.dict의 내용을 저장
		print_dict_error(argv[1], buffer); 	// dictionary랑 입력 단어 비교 (메인 알골 동작)
		free(buffer);
	}
	else if (argc == 3)  // 새로운 dict 사용해서 정수 처리
	{
		if (ft_check_number(argv[2]) == 0)
			return (0);
		buffer = ft_open_read_argv(argv[1]);	// 파일.dict 읽어와서 저장
		print_dict_error(argv[2], buffer);		// dictionary랑 입력 단어 비교 (메인 알골 동작)
		free(buffer);
	}
	return (0);
}
