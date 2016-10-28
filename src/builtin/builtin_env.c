#include "minishell.h"

int		builtin_env(char **av, char ***env_p)
{
	int		i;
	char	**env;

	i = 1;
	env = NULL;
	if (!av[1])
		ft_sstrprint(*env_p, '\n');
	else
	{
		while (av[i] && ft_strchr(av[i], '='))
		{
			env = ft_sstradd(env, av[i]);
			i++;
		}
		if (av[i])
			ft_cmd_process(av + i, env_p);
	}
	return (0);
}
