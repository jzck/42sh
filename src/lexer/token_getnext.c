#include "lexer.h"

static int is_separator(char c)
{
	return (c==' ' || c=='\t' || c=='\n');
}


static int is_stop_char(char c)
{
	return (c=='\0' || is_separator(c) ||
			c=='|' || c=='&' || c==';' || c=='<' || c=='>');
}

t_token		*token_getnext(int *pos, char *line)
{
	int		i;
	t_token	*token;

	i = 0;
	if (!line[*pos])
		return (NULL);
	token = token_init();
	while (is_separator(line[*pos]))
		(*pos)++;
	if (ft_strchr("|;", line[*pos]))
	{
		if (line[*pos] == ';')
			token->type = TK_SEMI;
		else if (line[*pos] == '|')
			token->type = TK_PIPE;
		token_append(token, line[(*pos)++]);
		return (token);
	}
	while (ft_isdigit(line[*pos]))
		token_append(token, line[(*pos)++]);
	if (ft_strchr("<>", line[(*pos)]))
	{
		token->type = (*pos == '>' ? TK_GREAT : TK_LESS);
		token_append(token, line[(*pos)++]);
		if (line[(*pos)] == *pos - 1)
			token->type = (token->type == TK_GREAT ? TK_DGREAT : TK_DLESS);
		else if (line[(*pos)] == '&')
		{
			token->type = (token->type == TK_GREAT ? TK_GREATAND : TK_LESSAND);
			token_append(token, line[(*pos)++]);
			while (ft_isdigit(line[*pos]))
				token_append(token, line[(*pos)++]);
			if (line[*pos] == '-')
				token_append(token, line[(*pos)++]);
		}
		return (token);
	}
	else
	{
		token->type = TK_WORD;
		while (!is_stop_char(line[*pos]))
			token_append(token, line[(*pos)++]);
		return (token);
	}
	return (token);
}
