#include "minishell.h"


t_stof g_builtin[] = {
	{"echo",		&builtin_echo},
	{"cd",			&builtin_cd},
	{"setenv",		&builtin_setenv},
	{"unsetenv",	&builtin_unsetenv},
	{"env",			&builtin_env},
	{"exit",		&builtin_exit},
	{NULL,			NULL},
};

int		ft_builtin(char **av, char ***env_p)
{
	int		i;
	int		ret;
	char	*exitval[2];
	char	**env;

	i = 0;
	env = *env_p;
	exitval[0] = ft_strdup("?");
	while (g_builtin[i].name)
	{
		if (ft_strcmp(g_builtin[i].name, *av) == 0)
		{
			ret = (g_builtin[i].f)(av, env_p);
			exitval[1] = ft_strdup(ft_itoa(ret));
			builtin_setenv(exitval, &env);
			*env_p = env;
			return (1);
		}
		i++;
	}
	return (0);
}
