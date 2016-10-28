#include "minishell.h"

int		ft_history_up(t_data *data, t_dlist **input_chain, char *buf)
{
	int		i;
	char	*str;

	(void)buf;
	if (!data->history)
		return (0);
	if (!data->history->prev)
		return (0);
	if (!data->history->next)
		data->history->content = ft_dlsttostr(*input_chain);
	data->history = data->history->prev;
	str = data->history->content;
	/* *input_chain = ft_dlst_last(*input_chain); */
	/* ft_clear_input(input_chain); */
	i = 0;
	while (str[i])
		ft_key_basic(data, input_chain, str + i++);
	if (!data->history->next)
		ft_strdel(&str);
	return (0);
}
