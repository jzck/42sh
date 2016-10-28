#include "minishell.h"

int		builtin_unsetenv(char **av, char ***env_p)
{
	char	**env;
	int		i;
	int		j;

	env = *env_p;
	/* ft_printf("builtin: %s\n", av[0]); */
	i = 1;
	while (av[i])
	{
		j = 0;
		while (env[j])
		{
			if (ft_strcmp(env[j], av[i]) == '=')
				ft_sstrdel(env, j);
			else
				j++;
		}
		i++;
	}
	return (0);
}
