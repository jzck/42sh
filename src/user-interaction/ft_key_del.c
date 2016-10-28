#include "minishell.h"

int		ft_key_del(t_data *data, t_dlist **input_chain, char *buf)
{
	char	*res;

	(void)data;
	(void)buf;
	if (!(*input_chain)->prev)
		return (0);
	if (*(char*)(*input_chain)->content == '\n')
		return (0);
	ft_dlst_delone(input_chain, &ft_lst_cfree);
	if ((res = tgetstr("le", NULL)) == NULL)
	{
		ft_printf("le error\n");
		return (-1);
	}
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	if ((res = tgetstr("DC", NULL)) == NULL)
	{
		ft_printf("DC error\n");
		return (-1);
	}
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (1);
}
