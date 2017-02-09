/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:50 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/10 00:33:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include "libft.h"
# include "types.h"

# define TK_LESS		(1 << 0)
# define TK_GREAT		(1 << 1)
# define TK_DLESS		(1 << 2)
# define TK_DGREAT		(1 << 3)
# define TK_LESSAND		(1 << 4)
# define TK_GREATAND	(1 << 5)
# define TK_SEMI		(1 << 6)
# define TK_PIPE		(1 << 7)
# define TK_AND_IF		(1 << 8)
# define TK_OR_IF		(1 << 9)
# define TK_AMP			(1 << 10)
# define TK_PAREN_OPEN	(1 << 11)
# define TK_PAREN_CLOSE	(1 << 12)
# define TK_BQUOTE		(1 << 13)
# define TK_N_WORD		(1 << 14)
# define TK_Q_WORD		(1 << 15)
# define TK_DQ_WORD		(1 << 16)
# define TK_COMMAND		(1 << 17)
# define TK_SUBSHELL	(1 << 18)
# define TK_NEWLINE		(1 << 19)

# define TK_WORD			(TK_N_WORD | TK_Q_WORD | TK_DQ_WORD)
# define TK_REDIR			(0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20)
# define TK_NON_FREEABLE	(TK_PAREN_OPEN | TK_PAREN_CLOSE | TK_BQUOTE)

enum	e_lexstate
{
	DEFAULT,
	NEWLINE,
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
	BQUOTE,
	BACKSLASH,
	SUBSHELL,
	COMMENT,
};

struct	s_token
{
	t_type			type;
	char			*data;
	unsigned char	*esc;
	unsigned char	*esc2;
	int				size;
};

struct	s_lexer
{
	char		*str;
	int			pos;
	t_lexstate	state;
	t_list		*stack;
};


extern int	(*g_lexer[])(t_list **alst, t_lexer *lexer);

int			ft_post_tokenize(t_list **alst, char **str);

t_token		*token_init();
int			token_append(t_token *token, t_lexer *lexer,
				short int esc, short int esc2);
void		token_free(void *data, size_t size);
int			token_cmp_type(t_token *token, t_type *ref);
void		token_print(t_list *lst);
void		token_expand_var(t_token *token);

int			reduce_parens(t_list **alst, char *str);
int			reduce_bquotes(t_list **alst, char **str);
char		*command_getoutput(char *command);

int			ft_is_delim(char c);
char		*stack_to_prompt(t_list	*stack);

t_lexstate	get_state_global(t_lexer *lexer);
t_lexstate	get_state_redir(t_lexer *lexer);
int			lexer_lex(t_list **alst, t_lexer *lexer);
int			lexer_default(t_list **alst, t_lexer *lexer);
int			lexer_newline(t_list **alst, t_lexer *lexer);
int			lexer_delim(t_list **alst, t_lexer *lexer);
int			lexer_sep(t_list **alst, t_lexer *lexer);
int			lexer_word(t_list **alst, t_lexer *lexer);
int			lexer_number(t_list **alst, t_lexer *lexer);
int			lexer_less(t_list **alst, t_lexer *lexer);
int			lexer_great(t_list **alst, t_lexer *lexer);
int			lexer_lessand(t_list **alst, t_lexer *lexer);
int			lexer_greatand(t_list **alst, t_lexer *lexer);
int			lexer_quote(t_list **alst, t_lexer *lexer);
int			lexer_dquote(t_list **alst, t_lexer *lexer);
int			lexer_bquote(t_list **alst, t_lexer *lexer);
int			lexer_backslash(t_list **alst, t_lexer *lexer);
int			lexer_subshell(t_list **alst, t_lexer *lexer);
int			lexer_comment(t_list **alst, t_lexer *lexer);

#endif
