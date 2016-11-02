#include "minishell.h"

int		ft_line_go_down(t_dlist **input_chain)
{
	char	*res;

	(void)input_chain;
	if ((res = tgetstr("up", NULL)) == NULL)
		return (-1);
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (0);
}
