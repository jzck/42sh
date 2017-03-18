#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	buf[PATH_MAX + 1];
	
	while (argc > 0)
	{
		bzero(buf, PATH_MAX + 1);
		realpath(argv[argc--], buf);
		remove(buf);
	}	
	return (0);
}
