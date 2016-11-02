#include "minishell.h"

int		ft_key_enter(t_data *data, t_dlist **input_chain, char *buf)
{
	if (ft_input_is_escaped(*input_chain))
	{
		ft_key_basic(data, input_chain, buf);
		ft_printf("> ");
		return (0);
	}
	ft_putchar('\n');
	ft_history_add(data, *input_chain);
	return (2);
}
