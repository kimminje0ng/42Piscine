/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:06:05 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/24 15:25:28 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <stdlib.h>
# include <unistd.h>

int		calculator(char **av);
int		main(int ac, char **av);

int		ft_add(char *a, char *b);
int		ft_sub(char *a, char *b);
int		ft_div(char *a, char *b);
int		ft_mul(char *a, char *b);
int		ft_rem(char *a, char *b);

int		ft_strcmp(char *s1, char *s2);
int		ft_check_zero(char *op, char *num);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif
