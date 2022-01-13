#include "cnt_mf.h"

static	int	cnt_m = 0;
static	int	cnt_f = 0;
static	int mindex = 0;

void	let_malloc_fail(void)
{
	mindex = (int)random() % 10;
}

char	*cnt_malloc(size_t size)
{
	char	*ans;
	ans = mindex < 8 ? malloc(size) : NULL;
	if (!ans)
		return (NULL);
	cnt_m++;
	return (ans);
}

void	cnt_free(char *f)
{
	if (f)
	{
		free(f);
		cnt_f++;
	}
}

void	put_mf(void)
{
	printf("malloc:%d\n", cnt_m);
	printf("free:%d\n", cnt_f);
}

void	put_judge(void)
{
	if (cnt_m == cnt_f)
	{
		printf("\x1b[32m");
		printf("leak ok\n");
	}
	else
	{
		printf("\x1b[31m");
		printf("leak maybe, if the difference is one(because of static), It's ok\n");
		printf("malloc:%d\n", cnt_m);
		printf("free:%d\n", cnt_f);
	}
	printf("\x1b[0m");
}
