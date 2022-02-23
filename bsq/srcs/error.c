#include "bsq.h"

int	error_message(int type)
{
	if (type == 1)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (0);
}
