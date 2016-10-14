#include "minishell.h"

int		builtin_setenv(char **av, char ***env_p)
{
	char	*str;
	char	**env;

	env = *env_p;
	if (ft_strcmp(av[0], "setenv") == 0)
		av++;
	if (!av[0])
		ft_sstrprint(*env_p, '\n');
	else
	{
		str = ft_str3join(av[0], "=", av[1]);
		while (*env)
		{
			/* ft_printf("%s\n", env[i]); */
			if (ft_strcmp(*env, av[0]) == '=')
			{
				*env = str;
				return (0);
			}
			env++;
		}
		*env_p = ft_sstradd(*env_p, str);
	}
	return (0);
}
