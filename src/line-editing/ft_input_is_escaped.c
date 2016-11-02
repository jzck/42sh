#include "minishell.h"

int		ft_input_is_escaped(t_dlist *input_chain)
{
	if (*(char *)input_chain->content == '\\')
		return (1);
	else
		return (0);
}
