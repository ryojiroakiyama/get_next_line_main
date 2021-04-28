#include "../get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void	extend(char ***ans, int cnt, char *line)
{
	char **tmp;
	int	i;

	tmp = *ans;
	*ans = (char **)malloc(sizeof(char *) * cnt);
	i = 0;
	while (i < cnt - 2)
	{
		(*ans)[i] = tmp[i];
		i++;
	}
	(*ans)[i] = line;
	(*ans)[++i] = NULL;
	free((char *)tmp);
}

int	main(void)
{
	char *line;
	int	sign = 1;
	int fd;
	int cnt = 1;
	char **ans;

	fd = 0;
	ans = (char **)malloc(sizeof(char *) * 1);
	if (!ans)
		return (0);
	ans[0] = NULL;
	while (sign != 0)
	{
		sign = get_next_line(fd, &line);		
		cnt++;
		extend(&ans, cnt, line);
		line = NULL;
	}
	cnt = 1;
	while (ans[cnt - 1] != NULL)
	{
		printf("cnt:%d\nline:%s\n", cnt, ans[cnt - 1]);
		put_mf();
		printf("------------------------\n");
		free(ans[cnt - 1]);
		cnt++;
	}
	free((char *)ans);

	put_mf();
	system("leaks a.out");
	return (0);
}
