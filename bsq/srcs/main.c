#include "bsq.h"

char	*ft_getbjc(char *str)
{
	int	i;

	i = 0;
	while (*str)
		str++;
	return (str - 3);
}

int	split_main(char **maps, int *lines, t_point *max_point)
{
	char	**s_map;
	int		**grid;
	int		max_value;
	t_point	len;

	s_map = ft_split(*maps, lines);
	if (valiate_first_line(s_map, lines) == 0)
		return (0);
	grid = make_grid(s_map, *lines);
	if (!s_map || !grid)
		return (0);
	len.x = *lines;
	len.y = ft_strlen(s_map[1]);
	grid = lgtm(grid, len.x, len.y);
	max_value = fantastic_baby(grid, len, max_point);
	print_map(grid, len, *max_point, ft_getbjc(s_map[0]));
	return (1);
}

int	main(int argc, char **argv)
{
	char	**maps;
	int		index;
	int		lines;
	t_point	max_point;

	lines = 0;
	index = 1;
	maps = (char **)malloc(sizeof(char *) * (argc - 1));
	while (index < argc)
	{
		*maps = read_file(argv[index]);
		if (!*maps)
			return (error_message(1));
		if (!split_main(maps, &lines, &max_point))
			return (error_message(1));
		index++;
		maps++;
	}
	return (0);
}
