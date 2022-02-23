#include "bsq.h"

int	**make_grid(char **s_map, int y)
{
	int		**grid;
	int		**temp;
	char	empty;
	char	obstacle;
	int		index;

	get_map_char(s_map[0], &empty, &obstacle);
	grid = (int **)malloc(sizeof(int *) * y);
	temp = grid;
	if (!grid)
		return (NULL);
	index = 1;
	while (s_map[index])
	{
		*grid = (int *)malloc(sizeof(int *) * ft_strlen(s_map[index]));
		if (!*grid)
			return (NULL);
		*grid = convert_row(s_map[index], ft_strlen(s_map[index]), &empty, \
				&obstacle);
		grid++;
		index++;
	}
	return (temp);
}

void	get_map_char(char *map, char *empty, char *obstacle)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	*empty = map[len - 3];
	*obstacle = map[len - 2];
}

int	*convert_row(char *row, int x, char *empty, char *obstacle)
{
	int	*irow;
	int	i;

	i = 0;
	irow = (int *)malloc(sizeof(int) * x);
	if (!irow)
		return (NULL);
	while (row[i])
	{
		if (row[i] == *empty)
			irow[i] = 1;
		else if (row[i] == *obstacle)
			irow[i] = 0;
		i++;
	}
	return (irow);
}
