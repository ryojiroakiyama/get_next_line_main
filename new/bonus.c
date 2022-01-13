#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char *line;
	char *file1;
	char *file2;
	int fd1;
	int fd2;

	if (argc == 3)
	{
		file1 = argv[1];
		file2 = argv[2];
		fd1 = open(file1, O_RDONLY);
		fd2 = open(file2, O_RDONLY);
		while (1)
		{
			line = get_next_line(fd1);
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
		close(fd1);
		close(fd2);
	}
	if (system("leaks a.out > /dev/null"))
		system("leaks a.out");
	return (0);
}
