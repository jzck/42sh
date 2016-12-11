#include "minishell.h"

t_data		*data_singleton()
{
	static t_data	*data = NULL;

	if (data == NULL)
		data = malloc(sizeof(t_data));
	return (data);
}
