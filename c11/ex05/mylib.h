#ifndef MYLIB_H
# define MYLIB_H

# include <stdlib.h>
# include <unistd.h>

int			do_op(int ac, char **av);

long long	ft_add(int a, int b);
long long	ft_sub(int a, int b);
long long	ft_div(int a, int b);
long long	ft_mul(int a, int b);
long long	ft_rem(int a, int b);

int			ft_intlen(long nb);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);

long long	ft_atoi(char *str);
void		tr_itoa(char *str, int num, int idx);
char		*ft_itoa(int num);

int			ft_check_zero(char *op, char *num);

#endif
