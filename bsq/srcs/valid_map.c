#include "bsq.h"

int	valiate_char_info(char *s_map)
{
	int	i;

	i = 0;
	while (s_map[i] != '\0')
		i++;
	if (i >= 4)
	{
		if ((s_map[i - 1] != s_map[i - 2]) && (s_map[i - 1] != s_map[i - 3]) && \
			(s_map[i - 2] != s_map[i - 3]))
		{
			if (is_printable(s_map[i - 3], s_map[i - 2], s_map[i - 1]))
				return (1);
		}
	}
	return (0);
}

int	valiate_line_number(char *s_map)
{
	int	s;
	int	e;

	s = 0;
	e = 0;
	while (s_map[e] != '\0')
		e++;
	e -= 4;
	while (s <= e)
	{
		if (s_map[s] >= '0' && s_map[s] <= '9')
			s++;
		else
			return (0);
	}
	return (s);
}

int	split_valiate_map(char **maps, int *i, int *len, int *x)
{
	int	j;

	j = 0;
	while (maps[*i][j] != '\0')
	{
		if (!(maps[*i][j] == maps[0][*len - 3] || maps[*i][j] == maps[0][*len \
				- 2]))
			return (0);
		j++;
	}
	if (*x != 0 && (*x != j))
		return (0);
	else
		*x = j;
	return (1);
}

int	valiate_map(char **maps, int nbr, int *lines)
{
	int	i;
	int	j;
	int	x;
	int	len;

	len = 0;
	while (maps[0][len])
		len++;
	i = 1;
	x = 0;
	while (maps[i] != 0)
	{
		if (!split_valiate_map(maps, &i, &len, &x))
			return (0);
		i++;
	}
	if (*lines == nbr)
		return (1);
	return (0);
}

int	valiate_first_line(char **s_map, int *y)
{
	int	nbr_length;
	int	nbr;

	if (!valiate_char_info(s_map[0]))
		return (0);
	nbr_length = valiate_line_number(s_map[0]);
	if (!nbr_length)
		return (0);
	nbr = ft_atoi(s_map[0], nbr_length);
	if (!valiate_map(s_map, nbr, y))
		return (0);
	return (1);
}
