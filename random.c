#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;

	while (i < 5)
	{
		printf("%d\n", (int)random() % 10);
		i++;
	}
	return (0);
}