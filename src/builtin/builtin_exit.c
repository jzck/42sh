#include "minishell.h"

int		builtin_exit(char **av, char ***env_p)
{
	int		status;

	(void)env_p;
	if (av[1])
		status = ft_atoi(av[1]);
	else
		status = ft_atoi(ft_env_getval(*env_p, "?"));
	exit(status);
	return (0);
}
