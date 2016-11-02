#include "minishell.h"

int	ft_key_basic(t_data *data, t_dlist **input_chain, char *buf)
{
	t_dlist	*new;
	char	*res;

	(void)data;
	new = ft_dlst_new(&buf[0], sizeof(char));
	ft_dlst_add_after(input_chain, new);
	if ((res = tgetstr("IC", NULL)) != NULL)
	{
		tputs(tgoto(res, 0, 0), 1, &ft_putchar);
		ft_putchar(buf[0]);
		return (0);
	}
	ft_putchar(buf[0]);
	return (0);
}
