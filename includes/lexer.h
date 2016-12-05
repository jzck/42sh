/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:50 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 13:14:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef long long		t_type;

# define TK_LESS		1 << 0
# define TK_GREAT		1 << 1
# define TK_DLESS		1 << 2
# define TK_DGREAT		1 << 3
# define TK_LESSAND		1 << 4
# define TK_GREATAND	1 << 5
# define TK_SEMI		1 << 6
# define TK_PIPE		1 << 7
# define TK_AND_IF		1 << 8
# define TK_OR_IF		1 << 9
# define TK_AMP			1 << 10
# define TK_WORD		1 << 11
# define TK_COMMAND		1 << 12

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
