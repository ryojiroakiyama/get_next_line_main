#include "../get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *line;
	char *file;
	int cnt = 1;
	int original_fd;
	int fd;
	int	sign = 1;

	if (argc == 3 && argv[2][0] == '0')//line == NULL section
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		printf("==>%s<==\n", file);
		sign = get_next_line(fd, 0);
		printf("sign:%d\n", sign);
		if (sign == -1)
		{
			printf("\x1b[31m");
			printf("value = -1 returned\n");
			printf("\x1b[0m");
		}
		close(fd);
		put_judge();
	}
	else if (argc == 3 && argv[2][0] == 'r' && argv[2][1] == 'f')//let read faile section
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		original_fd = fd;
		while (sign == 1)
		{
			printf("==>%s<==\n", file);
			if ((int)random() % 10 > 7)
				fd += 1;
			sign = get_next_line(fd, &line);
			printf("cnt:%d\nsign:%d\nline:%s\n", cnt, sign, line);
			cnt++;
			free(line);
			put_mf();
			if (sign == -1)
			{
				printf("\x1b[31m");
				printf("value = -1 returned\n");
				printf("\x1b[0m");
			}
		}
		close(original_fd);
		put_judge();
	}
	else if (argc == 3 && argv[2][0] == 'm' && argv[2][1] == 'f')//let malloc faile section
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		original_fd = fd;
		while (sign == 1)
		{
			printf("==>%s<==\n", file);
			let_malloc_fail();
			sign = get_next_line(fd, &line);
			printf("cnt:%d\nsign:%d\nline:%s\n", cnt, sign, line);
			cnt++;
			free(line);
			put_mf();
			if (sign == -1)
			{
				printf("\x1b[31m");
				printf("value = -1 returned\n");
				printf("\x1b[0m");
			}
		}
		close(original_fd);
		put_judge();
	}
//	system("leaks a.out");
	return (0);
}
