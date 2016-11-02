#include "minishell.h"

int		ft_key_ctrl_d(t_data *data, t_dlist **input_chain, char *buf)
{
	(void)data;
	(void)input_chain;
	(void)buf;
	ft_putendl("exit");
	exit(0);
}
