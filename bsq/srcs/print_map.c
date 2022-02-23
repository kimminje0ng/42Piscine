#include "bsq.h"

int	what_is_this(int **map, t_point max, t_point cur)
{
	int	max_value;

	max_value = map[max.x][max.y];
	if (map[cur.x][cur.y] == 0)
		return (1);
	if (cur.x >= max.x - (max_value - 1) && cur.x <= max.x)
	{
		if (cur.y >= max.y - (max_value - 1) && cur.y <= max.y)
			return (2);
		else
			return (0);
	}
	else
		return (0);
}

void	print_map(int **map, t_point map_size, t_point max, char *charset)
{
	t_point	cur;
	int		max_value;
	int		idx;

	max_value = map[max.x][max.y];
	cur.x = 0;
	while (cur.x < map_size.x)
	{
		cur.y = 0;
		while (cur.y < map_size.y)
		{
			idx = what_is_this(map, max, cur);
			write(1, &charset[idx], 1);
			cur.y++;
		}
		write(1, "\n", 1);
		cur.x++;
	}
}
