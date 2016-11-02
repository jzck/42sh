#include "minishell.h"

int		ft_clear_line(t_data *data, t_dlist **input_chain, char *buf)
{
	ft_line_end(data, input_chain, buf);
	while (ft_key_del(data, input_chain, buf))
		;
	return (1);
}
