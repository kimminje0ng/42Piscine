#include "bsq.h"

int	ft_atoi(char *s_map, int nbr_length)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (i < nbr_length)
	{
		result = result * 10 + (s_map[i] - '0');
		i++;
	}
	return (result);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_printable(char b, char o, char f)
{
	if ((b >= 32 && b <= 126) && (o >= 32 && o <= 126) && \
		(f >= 32 && f <= 126))
		return (1);
	return (0);
}
