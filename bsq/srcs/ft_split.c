#include "bsq.h"

int	count_word(char *str)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
		{
			cnt++;
			while (str[i] && str[i] != '\n')
				i++;
		}
	}
	return (cnt);
}

char	*malloc_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, int *y)
{
	char	**ret;
	int		i;
	int		j;

	*y = count_word(str) - 1;
	ret = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == '\n')
			i++;
		if (str[i] && str[i] != '\n')
		{
			ret[j++] = malloc_word(&str[i]);
			while (str[i] && str[i] != '\n')
				i++;
		}
	}
	ret[j] = 0;
	return (ret);
}
