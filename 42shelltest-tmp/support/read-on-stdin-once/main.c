#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	buf[1024];
	int		ret;

	if ((ret = read(0, buf, 1024)))
	{
		write(1, buf, ret);
		write(1, "@", 1);
	}
	if (ret < 0)
	{
		write(2, "STDIN READ ERROR\n", 17);
		return (1);
	}
	return (0);
}
