#include "../get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *line;
	char *file;
	int i;
	int cnt = 1;
	int	fd_b[5];
	int sign_b[5] = {0, 0, 0, 0, 0};

	i = 0;
	while (i + 1 < argc)
	{
		file = argv[i + 1];
		fd_b[i] = open(file, O_RDONLY);
		i++;
	}
	cnt = 1;
	sign_b[0] = 1;
	while (sign_b[0] != 0 || sign_b[1] != 0 || sign_b[2] != 0 || sign_b[3] != 0 || sign_b[4] != 0)
	{
		i = 0;
		while (i + 1 < argc)
		{
			printf("==>%s<==\n", argv[i + 1]);
			sign_b[i] = get_next_line(fd_b[i], &line);
			printf("cnt:%d\nsign:%d\nline:%s\n", cnt, sign_b[i], line);
			free(line);
			i++;
		}
		cnt++;
	}
	i = 0;
	while (i + 1 < argc)
	{
		close(fd_b[i]);
		i++;
	}

	system("leaks a.out");
	return (0);
}
