#include "minishell.h"

extern char	**environ;

int		data_init(t_data *data)
{
	data->env = ft_sstrdup(environ);
	data->history = NULL;
	if (!(data->history = ft_dlstnew(NULL, 0)))
		return (-1);
	return (0);
}
