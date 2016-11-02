#include "minishell.h"

int		ft_line_end(t_data *data, t_dlist **input_chain, char *buf)
{
	while (ft_cursor_right(data, input_chain, buf))
		;
	return (0);
}
