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

int		ft_builtin(char **av, char ***env_p)
{
	int		i;

	i = 0;
	while (g_builtin[i].name)
	{
		if (ft_strcmp(g_builtin[i].name, *av) == 0)
		{
			(g_builtin[i].f)(av, env_p);
			return (1);
		}
		i++;
	}
	return (0);
}
