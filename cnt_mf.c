#include "cnt_mf.h"

static	int	cnt_m = 0;
static	int	cnt_f = 0;

char	*cnt_malloc(size_t size)
{
	char	*ans;
	ans = malloc(size);
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
	printf("cnt_m:%d\n", cnt_m);
	printf("cnt_f:%d\n", cnt_f);
}
