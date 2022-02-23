#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 4096

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

int				ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_atoi(char *file, int nbr_length);
int				is_printable(char b, char o, char f);

int				**make_grid(char **s_map, int y);
int				*convert_row(char *row, int x, char *empty, char *obstacle);
void			get_map_char(char *map, char *empty, char *obstacle);

int				valiate_char_info(char *file);
int				valiate_line_number(char *s_map);
int				valiate_map(char **file, int nbr, int *lines);
int				valiate_first_line(char **s_map, int *y);

int				get_file_size(char *file);
char			*read_file(char *file);

int				count_word(char *str);
char			*malloc_word(char *str);
char			**ft_split(char *str, int *y);

int				error_message(int type);

int				get_min(int num1, int num2, int num3);
int				**lgtm(int **map, int x, int y);
int				fantastic_baby(int **map, t_point len, t_point *cass);

int				what_is_this(int **map, t_point max, t_point cur);
void			print_map(int **map, t_point map_size, t_point max, \
				char *charset);

#endif
