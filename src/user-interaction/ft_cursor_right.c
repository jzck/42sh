#include "minishell.h"

int		ft_cursor_right(t_data *data, t_dlist **input_chain, char *buf)
{
	char	*res;

	res = NULL;
	(void)buf;
	(void)data;
	if (*(char*)(*input_chain)->content == '\n')
		return (0);
	if (!(*input_chain)->next)
		return (0);
	*input_chain = (*input_chain)->next;
	if ((res = tgetstr("nd", NULL)) == NULL)
		return (-1);
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (1);
}
