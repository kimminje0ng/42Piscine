#include "bsq.h"

int	get_min(int num1, int num2, int num3)
{
	int	min;

	min = num1;
	if (num2 < min)
		min = num2;
	if (num3 < min)
		min = num3;
	return (min);
}

// 장애물은 0, 빈 곳은 1로 초기화된 상태로 넘어옴
int	**lgtm(int **map, int x, int y)
{
	int	col;
	int	la;
	int	fuck1;
	int	fuck2;
	int	fuck3;

	col = 0;
	while (col < x)
	{
		la = 0;
		while (la < y)
		{
			if (col >= 1 && la >= 1 && map[col][la] == 1)
			{
				fuck1 = map[col - 1][la - 1];
				fuck2 = map[col - 1][la];
				fuck3 = map[col][la - 1];
				map[col][la] = get_min(fuck1, fuck2, fuck3) + 1;
			}
			la++;
		}
		col++;
	}
	return (map);
}

// 맵에서 최대값찾아서 리턴
int	fantastic_baby(int **map, t_point len, t_point *cass)
{
	t_point	big;
	int		bang;

	big.x = len.x - 1;
	big.y = len.y - 1;
	bang = map[big.x][big.y];
	while (big.x >= 0)
	{
		big.y = len.y - 1;
		while (big.y >= 0)
		{
			if (map[big.x][big.y] >= bang)
			{
				bang = map[big.x][big.y];
				cass->x = big.x;
				cass->y = big.y;
			}
			big.y--;
		}
		big.x--;
	}
	return (map[cass->x][cass->y]);
}
