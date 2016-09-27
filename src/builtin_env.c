#include "minishell.h"

int		builtin_setenv(char **av, char **env)
{
	(void)env;
	ft_printf("builtin: %s\n", av[0]);
	return (0);
}

int		builtin_unsetenv(char **av, char **env)
{
	(void)env;
	ft_printf("builtin: %s\n", av[0]);
	return (0);
}

int		builtin_env(char **av, char **env)
{
	(void)env;
	ft_printf("builtin: %s\n", av[0]);
	return (0);
}
