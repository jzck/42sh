/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:50 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/01 16:21:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

# define TK_LESS		0x00000001
# define TK_GREAT		0x00000002
# define TK_DLESS		0x00000004
# define TK_DGREAT		0x00000008
# define TK_LESSAND		0x00000010
# define TK_GREATAND	0x00000020
# define TK_SEMI		0x00000040
# define TK_PIPE		0x00000080
# define TK_AND_IF		0x00000100
# define TK_OR_IF		0x00000200
# define TK_AMP			0x00000400
# define TK_WORD		0x00100000
# define TK_COMMAND		0x00200000

# define TK_REDIR		(0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20)

enum	e_lexstate
{
	DEFAULT,
	DELIM,
	SEP,
	WORD,
	NUMBER,
	GREAT,
	LESS,
	GREATAND,
	LESSAND,
	QUOTE,
	DQUOTE,
	BACKSLASH,
};

struct	s_token
{
	t_type		type;
	char		*data;
	int			size;
};

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef enum e_lexstate	t_lexstate;

extern int	(*g_lexer[])(t_list **alst, char *str);

t_token	*token_init();
int		ft_tokenize(t_list **alst, char *str, t_lexstate state);
int		token_append(t_token *token, char c);
void	token_free(void *data, size_t size);
int		token_cmp_type(t_token *token, t_type *ref);
void	token_print(t_list *lst);

int		ft_is_delim(char c);
void	qstate_update(t_data *data, char c);

int		lexer_default(t_list **alst, char *str);
int		lexer_delim(t_list **alst, char *str);
int		lexer_sep(t_list **alst, char *str);
int		lexer_word(t_list **alst, char *str);
int		lexer_number(t_list **alst, char *str);
int		lexer_less(t_list **alst, char *str);
int		lexer_great(t_list **alst, char *str);
int		lexer_lessand(t_list **alst, char *str);
int		lexer_greatand(t_list **alst, char *str);
int		lexer_quote(t_list **alst, char *str);
int		lexer_dquote(t_list **alst, char *str);
int		lexer_backslash(t_list **alst, char *str);

#endif
