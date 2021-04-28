#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *line;
	int	sign = 1;
	int fd;
	int cnt = 1;
	char *file;

//	file = argv[argc - 1];
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (argv[argc - 1][0] == '0')
	{
		sign = get_next_line(fd, 0);
		printf("sign:%d\n", sign);
		printf("------------------------\n");
	}
	else
	{
		while (sign != 0)
		{
			sign = get_next_line(fd, &line);
			printf("cnt:%d\nsign:%d\nline:%s\n", cnt, sign, line);
			cnt++;
			free(line);
			put_mf();
			printf("------------------------\n");
		}
		sign = get_next_line(fd, &line);
		printf("one more\nsign:%d\nline:%s\n", sign, line);
		free(line);
		put_mf();
		printf("------------------------\n");
	}
	close(fd);

	/*
	(void)argc;
	(void)argv;
	file = "../Get_Next_Line_Tester/test/normal.txt";
	fd = open(file, O_RDONLY);
	while (sign != 0)
	{
		sign = get_next_line(fd, &line);
		printf("cnt:%d\nsign:%d\nline:%s\n", cnt, sign, line);
		printf("------------------------\n");
		cnt++;
		free(line);
	}
	sign = get_next_line(fd, &line);
	printf("one more\nsign:%d\nline:%s\n", sign, line);
	printf("------------------------\n");
	free(line);
	close(fd);
*/

	system("leaks a.out");
	return (0);
}
