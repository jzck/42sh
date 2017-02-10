/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:50 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/10 01:43:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef long long		t_type;

/*
 * Token need :
 * DLESSDASH
 * CLOBBER
 * LESSGREAT
 * IO_NUMBER
 * NAME
 * DSEMI
 * ASSIGNEMENT_WORD
 * Lbrace
 * Rbrace
 * Bang
 * Case
 * Esac
 * for
 * in
 *
*/

/*

# define TK_LESS		(1 << 0)	//transparent
# define TK_GREAT		(1 << 1)	//transparent
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
# define TK_WHILE		(1 << 20)
# define TK_DO			(1 << 21)
# define TK_DONE		(1 << 22)
# define TK_IF			(1 << 23)
# define TK_THEN		(1 << 24)
# define TK_FI			(1 << 25)
# define TK_ELIF		(1 << 26)
# define TK_ELSE		(1 << 27)
# define TK_UNTIL		(1 << 28)

*/

# define TK_COMMAND			(1 << 10)
# define TK_WORD			(TK_N_WORD | TK_Q_WORD | TK_DQ_WORD)
# define TK_REDIR			(0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20)
# define TK_NON_FREEABLE	(TK_PAREN_OPEN | TK_PAREN_CLOSE | TK_BQUOTE)
# define RW_SEP				(TK_NEWLINE | TK_AMP | TK_SEMI | TK_WHILE | TK_DONE\
							| TK_DO | TK_IF | TK_FI | TK_THEN | TK_ELIF | TK_ELSE)

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
	BACKSLASH,
	VAR,
	SPECIAL,
	WHILE,
	DO,
	DONE,
	IF,
	THEN,
	FI,
	COMMENT,
};

struct	s_token
{
	t_type			type;
	char			*data;
	unsigned char	*esc;
	int				size;
};

typedef struct s_data	t_data;
typedef struct s_token	t_token;
typedef enum e_lexstate	t_lexstate;

extern int	(*g_lexer[])(t_list **alst, char *str);

int			ft_lexer(t_list **alst, char **str);
int			ft_tokenize(t_list **alst, char *str, t_lexstate state);
int			ft_post_tokenize(t_list **alst, char **str);

t_token		*token_init();
int			token_append(t_token *token, char c, short int esc);
void		token_free(void *data, size_t size);
int			token_cmp_type(t_token *token, t_type *ref);
void		token_print(t_list *lst);
void		token_expand_var(t_token *token);

int			reduce_parens(t_list **alst, char *str);
int			reduce_bquotes(t_list **alst, char **str);
char		*command_getoutput(char *command);

int			ft_is_delim(char c);
int			ft_is_delim_list(char c);

t_lexstate	get_lexer_state(char *str);
int			get_reserved_words(t_list **alst);
int			lexer_default(t_list **alst, char *str);
int			lexer_newline(t_list **alst, char *str);
int			lexer_delim(t_list **alst, char *str);
int			lexer_sep(t_list **alst, char *str);
int			lexer_word(t_list **alst, char *str);
int			lexer_number(t_list **alst, char *str);
int			lexer_less(t_list **alst, char *str);
int			lexer_great(t_list **alst, char *str);
int			lexer_lessand(t_list **alst, char *str);
int			lexer_greatand(t_list **alst, char *str);
int			lexer_quote(t_list **alst, char *str);
int			lexer_dquote(t_list **alst, char *str);
int			lexer_backslash(t_list **alst, char *str);
int			lexer_var(t_list **alst, char *str);
int			lexer_special(t_list **alst, char *str);
int			lexer_while(t_list **alst, char *str);
int			lexer_do(t_list **alst, char *str);
int			lexer_done(t_list **alst, char *str);
int			lexer_if(t_list **alst, char *str);
int			lexer_then(t_list **alst, char *str);
int			lexer_fi(t_list **alst, char *str);
int			lexer_list(t_list **alst, char *str);
int			lexer_comment(t_list **alst, char *str);

#endif
