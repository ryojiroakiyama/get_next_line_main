#include "../get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *line;
	char *file;
	int fd;
	int	sign = 1;

	(void)argc;
	file = argv[1];
	fd = open(file, O_RDONLY);
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
