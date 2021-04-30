#ifndef CNT_MF_H
# define CNT_MF_H

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	let_malloc_fail(void);
char	*cnt_malloc(size_t size);
void	cnt_free(char *f);
void	put_mf(void);
void	put_judge(void);

# endif
