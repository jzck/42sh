#include "minishell.h"

char	*ft_env_getval(char **env, char *key)
{
	if (!env)
		return (NULL);
	while (*env)
	{
		/* ft_printf("%s\n", env[i]); */
		if (ft_strcmp(*env, key) == '=')
			return (*env + ft_strlen(key) + 1);
		env++;
	}
	return (NULL);
}
