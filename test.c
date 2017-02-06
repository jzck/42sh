#include <stdio.h>

int		main(void)
{
	int		loop;

	loop = 1;
	printf("hello world");
	if (loop)
		main();
	return (0);
}
