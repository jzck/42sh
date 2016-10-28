#include "minishell.h"

void	ft_expand_dollar(char **av, char **env)
{
	char	*dollar;

	while (*av)
	{
		if ((dollar = ft_strchr(*av, '$')))
		{
			*dollar = '\0';
			*av = ft_strjoin(*av, ft_env_getval(env, dollar + 1));
		}
		av++;
	}
}
