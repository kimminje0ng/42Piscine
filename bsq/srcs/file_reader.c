#include "bsq.h"

int	get_file_size(char *file)
{
	int		total_size;
	char	buf[BUF_SIZE];
	int		fd;
	int		size;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = read(fd, buf, BUF_SIZE);
	total_size = 0;
	while (size > 0)
	{
		total_size += size;
		size = read(fd, buf, BUF_SIZE);
	}
	if (fd >= 3)
		close(fd);
	if (size < 0)
		return (-1);
	return (total_size);
}

char	*read_file(char *file)
{
	char	*dst;
	int		total_size;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	total_size = get_file_size(file);
	if (total_size == 0)
		return (NULL);
	dst = (char *)malloc(sizeof(char *) * (total_size + 1));
	if (!dst)
		return (dst);
	dst[total_size] = '\0';
	if (read(fd, dst, total_size) < 0)
	{
		free(dst);
		dst = NULL;
	}
	if (fd >= 3)
		close(fd);
	return (dst);
}
