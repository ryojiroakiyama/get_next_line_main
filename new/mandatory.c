#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char *line;
	char *file;
	int fd;

	if (argc == 1)//stdin
	{
		while (1)
		{
			line = get_next_line(STDIN_FILENO);
			if (line)
				printf("%s", line);
			else
				break;
			free(line);
		}
	}
	else if (argc == 2)//from file
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			if (line)
				printf("%s", line);
			else
				break;
			free(line);
		}
		close(fd);
	}
	else if (argc == 3)//error
	{
		while (1)
		{
			line = get_next_line(42);
			if (line)
				printf("%s", line);
			else
			{
				printf("ok");
				break;
			}
			free(line);
		}
	}
	if (system("leaks a.out > /dev/null"))
		system("leaks a.out");
	return (0);
}
