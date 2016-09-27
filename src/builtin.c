#include "minishell.h"

t_builtin g_builtin[] = {
	{"echo", &builtin_echo},
	{"cd", &builtin_cd},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"env", &builtin_env},
	{"exit", &builtin_exit},
	{NULL, NULL},
};

int		ft_builtin_exec(char **av, char **env)
{
	int		i;

	i = 0;
	while (g_builtin[i].name)
	{
		if (ft_strcmp(g_builtin[i].name, *av) == 0)
		{
			(g_builtin[i].f)(av, env);
			return (0);
		}
		i++;
	}
	return (1);
}

int		builtin_echo(char **av, char **env)
{
	(void)env;
	av++;
	while (*av)
	{
		ft_printf("%s", *av);
		av++;
		if (*av)
			ft_putstr(" ");
	}
	ft_putendl("");
	return (0);
}

int		builtin_cd(char **av, char **env)
{
	(void)env;
	ft_printf("builtin: %s\n", av[0]);
	return (0);
}

int		builtin_exit(char **av, char **env)
{
	(void)env;
	ft_printf("builtin: %s\n", av[0]);
	return (0);
}
