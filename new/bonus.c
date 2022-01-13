#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c -I <headerdir>

int	main(int argc, char *argv[])
{
	char *line;
	char *file;
	char *file2;
	int fd;
	int fd2;

	if (argc == 3)
	{
		file = argv[1];
		file2 = argv[2];
		fd = open(file, O_RDONLY);
		fd2 = open(file2, O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			if (line)
				printf("%s", line);
			else
				break;
			free(line);
			line = get_next_line(fd2);
			if (line)
				printf("%s", line);
			else
				break;
			free(line);
		}
		close(fd);
		close(fd2);
	}
	if (system("leaks a.out > /dev/null"))
		system("leaks a.out");
	return (0);
}
