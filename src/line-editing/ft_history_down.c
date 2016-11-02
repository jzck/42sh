#include "minishell.h"

int		ft_history_down(t_data *data, t_dlist **input_chain, char *buf)
{
	int		i;
	char	*str;

	(void)buf;
	if (!data->history)
		return (0);
	if (!data->history->next)
		return (0);
	data->history = data->history->next;
	str = data->history->content;
	*input_chain = ft_dlst_last(*input_chain);
	/* ft_clear_input(input_chain); */
	i = 0;
	while (str[i])
		ft_key_basic(data, input_chain, str + i++);
	if (!data->history->next)
		ft_strdel(&str);
	return (0);
}
