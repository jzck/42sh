#include "minishell.h"

void	qstate_update(t_data *data, char c)
{
	t_qstate	*now;
	t_qstate	*last;

	now = &data->state_now;
	last = &data->state_last;
	if (*now == Q_NONE)
	{
		if (c == '\\')
		{
			*last = Q_NONE;
			*now = Q_BACKSLASH;
		}
		*now = c == '\'' ? Q_QUOTE : *now;
		*now = c == '\"' ? Q_DQUOTE : *now;
	}
	else if (*now == Q_QUOTE)
		*now = c == '\'' ? Q_NONE : *now;
	else if (*now == Q_DQUOTE)
	{
		if (c == '\\')
		{
			*last = Q_DQUOTE;
			*now = Q_BACKSLASH;
		}
		*now = c == '\"' ? Q_NONE : *now;
	}
	else if (*now == Q_BACKSLASH)
	{
		*now = *last;
	}
}
