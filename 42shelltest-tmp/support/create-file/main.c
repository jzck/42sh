#include <fcntl.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char		*name;
	static char	filename[1000];
		
	(void)argc;
	if (!argv[1])
		strcat(filename, "TOKEN");
	else
		strcat(filename, argv[1]);
	name = "_FILE";
	strcat(filename, name);
	creat(filename, 0644);
	return (0);
}
