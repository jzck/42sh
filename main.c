#include <stdlib.h>

int		main(void)
{
	char	*s;

	s = malloc(5);
	fork();
	free(s);
	sleep(100);
	return (0);
}
