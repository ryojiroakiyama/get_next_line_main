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
	int original_fd;
	int fd;
	int	sign = 1;
	int	fd_b[5];
	int sign_b[5] = {0, 0, 0, 0, 0};

	if (argc == 1)
	{
		printf("no file\n");
		return (0);
	}
	if (argc == 3 && argv[2][0] == '0')//line == NULL section
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		printf("==>%s<==\n", file);
		sign = get_next_line(fd, 0);
		printf("sign:%d\n", sign);
		close(fd);
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
//			put_mf();
			if (sign == -1)
			{
				printf("\x1b[31m");
				printf("error detected\n");
				printf("\x1b[0m");
			}
		}
		close(original_fd);
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
//			put_mf();
			if (sign == -1)
			{
				printf("\x1b[31m");
				printf("error detected\n");
				printf("\x1b[0m");
			}
		}
		close(original_fd);
	}
	else if (argc == 2)//mandatory section
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		while (sign == 1)
		{
			sign = get_next_line(fd, &line);
			printf("==>%s<==\n", file);
			printf("cnt:%d\nsign:%d\nline:%s\n", cnt, sign, line);
			cnt++;
			free(line);
//			put_mf();
		}
		sign = get_next_line(fd, &line);//for comfirm action when recall
		printf("one more\nsign:%d\nline:%s\n", sign, line);
		free(line);
		put_mf();
		printf("------------------------\n");
		close(fd);
	}
	else if (argc <= 6)//bonus section
	{
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
//				put_mf();
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
	}
	else
		printf("too many files\n");

	printf("-----------------------------");
	put_judge();
/*
//	for valgrind part
	(void)argc;
	(void)argv;
	char *file;
	int	fd;
	char *line;
	int sign = 1;
	int cnt = 1;
	file = "./random";
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
