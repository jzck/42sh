#include "minishell.h"

int		builtin_echo(char **av, char ***env_p)
{
	(void)env_p;
	av++;
	while (*av)
	{
		ft_printf("%s", *av);
		av++;
		if (*av)
			ft_putstr(" ");
	}
	ft_putchar('\n');
	return (0);
}
