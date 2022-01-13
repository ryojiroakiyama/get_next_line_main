#include "../get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd;
	int	sign = 1;

	fd = 0;
	while (sign == 1)
	{
		sign = get_next_line(fd, &line);
		printf("%s", line);
		free(line);
		if (sign == 1)
			printf("\n");
	}
	close(fd);
	
	return (0);
}
