#include "minishell.h"

int		builtin_cd(char **av, char ***env)
{
	(void)env;
	ft_printf("builtin: %s\n", av[0]);
	return (0);
}
