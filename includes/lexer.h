/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:50 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/19 17:13:05 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"
# include "libft.h"
# include "types.h"

# define RW_SEP				(TK_NEWLINE | TK_AMP | TK_SEMI | TK_WHILE | TK_DONE\
							| TK_DO | TK_IF | TK_FI | TK_THEN | TK_ELIF | TK_ELSE)
enum	e_lexstate
{
	DEFAULT,
	PAREN,
	HEREDOC,
	NEWLINE,
	DELIM,
	SEP,
	WORD,
	NUMBER,
	LESS,
	GREAT,
	QUOTE,
	DQUOTE,
	BQUOTE,
	BACKSLASH,
	CURLY_BRACKETS,
	END,
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
	t_list		*heredoc_stack;
};

struct	s_rvwords
{
	char	*word;
	int		type;
};

extern t_rvwords g_rvwords[];

extern int	(*g_lexer[])(t_list **alst, t_lexer *lexer);

int			ft_post_tokenize(t_list **alst, char **str);

t_token		*token_init();
int			token_append(t_token *token, t_lexer *lexer,
				short int esc, short int esc2);
int			token_append_char(t_token *token, char c,
				short int esc, short int esc2);
int			token_append_str(t_token *token, char *str,
				short int esc, short int esc2);
void		token_free(void *data, size_t size);
int			token_cmp_type(t_token *token, t_type *ref);
void		token_print(t_list *lst);

int			reduce_parens(t_list **alst, char *str);
int			bquotes_expand(t_list **alst);
char		*command_getoutput(char *command, char *const av[], char **env, int pipe_mode);

int			ft_is_delim(char c);
int			ft_is_delim_list(char c);

char		*stack_to_prompt(t_list	*stack);
t_lexstate	get_state_global(t_lexer *lexer);
t_lexstate	get_state_redir(t_lexer *lexer);
int			get_lexer_stack(t_lexer lexer);
int			get_reserved_words(t_list *temp);
int			insert_newline(t_list **alst);

int			do_lexer_routine(t_list **token, char *stream);
void		lexer_init(t_lexer *lexer);
void		lexer_destroy(t_lexer *lexer);
int			lexer_lex(t_list **alst, t_lexer *lexer);
int			lexer_default(t_list **alst, t_lexer *lexer);
int			lexer_newline(t_list **alst, t_lexer *lexer);
int			lexer_heredoc(t_list **alst, t_lexer *lexer);
int			lexer_delim(t_list **alst, t_lexer *lexer);
int			lexer_sep(t_list **alst, t_lexer *lexer);
int			lexer_word(t_list **alst, t_lexer *lexer);
int			lexer_number(t_list **alst, t_lexer *lexer);
int			lexer_less(t_list **alst, t_lexer *lexer);
int			lexer_great(t_list **alst, t_lexer *lexer);
int			lexer_greatand(t_list **alst, t_lexer *lexer);
int			lexer_lessand(t_list **alst, t_lexer *lexer);
int			lexer_quote(t_list **alst, t_lexer *lexer);
int			lexer_dquote(t_list **alst, t_lexer *lexer);
int			lexer_bquote(t_list **alst, t_lexer *lexer);
int			lexer_backslash(t_list **alst, t_lexer *lexer);
int			lexer_paren(t_list **alst, t_lexer *lexer);
int			lexer_curly_braces(t_list **alst, t_lexer *lexer);
int			lexer_assignement_word(t_list **alst, t_lexer *lexer);
int			lexer_comment(t_list **alst, t_lexer *lexer);
int			lexer_end(t_list **alst, t_lexer *lexer);

#endif
