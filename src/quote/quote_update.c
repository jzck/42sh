#include "libft.h"

void	quote_state_update(t_data *data, char c)
{
	t_quote		now;
	t_quote		last;

	now = data->state_now;
	last = data->state_last;
	if (c == '\\' && now != DQUOTE)
	{
		if (now == BACKSLASH)
			now = last;	
		else
			now = BACKSLASH;
	}
	if (quote != BACKSLASH)
	{
		if (c == '\'')
			quoted = now == QUOTE ? 0 : '\'';
		if (c == '\"' )
			data->quoted = now == DQUOTE ? 0 : '\"';
	}
}
