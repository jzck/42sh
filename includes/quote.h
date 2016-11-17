#ifndef LINE_EDITING_H
# define LINE_EDITING_H

typedef enum e_quote	t_quote;

enum	e_quote
{
	NONE,
	QUOTE,
	DQUOTE,
	BACKSLASH,
};

void	quote_update(t_data *data, char c);

#endif
