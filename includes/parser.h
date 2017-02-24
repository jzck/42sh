/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:54 by jhalford          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
 * Parse POSIX grammar
 *
*/

enum	e_parstate
{
	ERROR = 0,
	UNDEFINED,
	SUCCESS,
};

enum	e_sym
{
	LINEBREAK = 1,
	TK_COMMAND,
	TK_LESS,
	TK_GREAT,
	TK_DLESS,
	TK_DGREAT,
	TK_LESSAND,
	TK_GREATAND,
	TK_SEMI,
	TK_PIPE,
	TK_AND_IF,
	TK_OR_IF,
	TK_AMP,
	TK_PAREN_OPEN,
	TK_PAREN_CLOSE,
	TK_BQUOTE,
	TK_NEWLINE,
	TK_WHILE,
	TK_DO,
	TK_DONE,
	TK_IF,
	TK_THEN,
	TK_FI,
	TK_ELIF,
	TK_ELSE,
	TK_UNTIL,
	TK_WORD,
	TK_ASSIGNEMENT_WORD = 50,
	TK_BANG,
	TK_NAME,
	TK_FOR,
	TK_IO_NUMBER,
	TK_DLESSDASH,
	TK_LESSGREAT,
	TK_SUBSHELL,
	TK_CASE,
	TK_IN,
	TK_ESAC,
	TK_CLOBBER,
	TK_LBRACE,
	TK_RBRACE,
	TK_DSEMI,
	PROGRAM = 100,
	COMPLETE_COMMAND,
	COMPLETE_COMMANDS,
	LIST,
	AND_OR,
	PIPELINE,
	PIPE_SEQUENCE,
	COMMAND,
	COMPOUND_COMMAND,
	SUBSHELL,
	COMPOUND_LIST,
	TERM,
	FOR_CLAUSE,
	NAME,
	IN,
	WORDLIST,
	CASE_CLAUSE,
	CASE_LIST,
	CASE_LIST_NS,
	CASE_ITEM,
	CASE_ITEM_NS,
	PATTERN,
	IF_CLAUSE,
	BRACE_CLAUSE,
	ELSE_PART,
	WHILE_CLAUSE,
	UNTIL_CLAUSE,
	FUNCTION_DEFINITION,
	FUNCTION_BODY,
	FNAME,
	BRACE_GROUP,
	DO_GROUP,
	SIMPLE_COMMAND,
	CMD_NAME,
	CMD_WORD,
	CMD_PREFIX,
	CMD_SUFFIX,
	REDIRECT_LIST,
	IO_REDIRECT,
	IO_FILE,
	FILENAME,
	IO_HERE,
	HERE_END,
	NEWLINE_LIST,
	SEPARATOR_OP,
	SEPARATOR,
	SEQUENTIAL_SEP,
	BRACE,
	LOOP,
	FUNC,
	PIPE_SEMI_SEQUENCE,
	CMD_SUPERIOR,
	AND_OR_MAJOR,
	AND_OR_MINOR,
	END_COMMAND,
	CONDITION,
	COMPLETE_CONDITION,
	FOR_WORDLIST,
	PATTERN_CASE,
	FUNC_NAME,
	CLOSE_LIST,
	ALL = 200,
};

# define TK_REDIR(x)			(TK_LESS <= x && x <= TK_GREATAND)

# define MATCH_STACK(x, y)		(x == y || y == ALL)

struct	s_parser
{
	t_parstate	state;
	t_sym		*stack;
	t_sym		*new_sym;
};

struct	s_aggrematch
{
	t_sym 	top;
	t_sym 	under;
	t_sym 	new_sym;
	int	erase_sym;
};

extern t_aggrematch g_aggrematch[];

struct	s_prodmatch
{
	t_type	token;
	t_sym	stack;
	t_sym	new_sym;
};

extern t_prodmatch g_prodmatch[];

struct	s_stackmatch
{
	t_sym top;
	t_sym under;
};

extern t_stackmatch g_stackmatch[];

struct	s_errormatch
{
	t_type	token;
	char	*error;
};

extern t_errormatch	g_errormatch[];

void	parser_init(t_parser *parser);
int		ft_parse(t_btree **ast, t_list **token, t_parser *parser);

int		produce_sym(t_sym stack, t_sym *new_sym, t_list **lst);
int		eval_sym(t_sym stack, t_sym new_sym);
int		aggregate_sym(t_sym **stack, t_sym *new_sym, t_parstate *state);

int		push_stack(t_sym *stack, t_sym new_sym);
int		pop_stack(t_sym **stack, t_sym erase_sym);

int		error_syntax(t_list **token);
int		error_EOF(void);

int		ft_read_stack(t_sym *stack);
char		*read_state(t_sym current);


/*
 * Build AST - rewriting
 *
*/

struct	s_treematch
{
	t_type	type;
	int	(*add)(t_btree **ast, t_list **lst);
};

extern t_treematch g_treematch[];

int		build_tree(t_btree **ast, t_list **lst);

int		add_sep(t_btree **ast, t_list **lst);
int		add_cmd(t_btree **ast, t_list **lst);
int		add_file(t_btree **ast, t_list **lst);
int		add_loop_cmd(t_btree **ast, t_list **lst);
int		add_loop_sep(t_btree **ast, t_list **lst);
int		add_loop_condition(t_btree **ast, t_list **lst);
int		add_condition_cmd(t_btree **ast, t_list **lst);
int		add_condition_sep(t_btree **ast, t_list **lst);
int		add_branch(t_btree **ast, t_list **lst);
int		add_case_cmd(t_btree **ast, t_list **lst);
int		add_case_sep(t_btree **ast, t_list **lst);
int		add_pattern(t_btree **ast, t_list **lst);
int		add_subshell_cmd(t_btree **ast, t_list **lst);
int		add_subshell_sep(t_btree **ast, t_list **lst);
int		add_func_cmd(t_btree **ast, t_list **lst);
int		add_func_sep(t_btree **ast, t_list **lst);
int		isloop(t_btree **ast, t_list **lst);
int		isdir(t_btree **ast);
int		iscase(t_btree **ast, t_list **lst);
int		iscondition(t_btree **ast, t_list **lst);
int		issubshell(t_btree **ast, t_list **lst);
int		isfunc(t_btree **ast, t_list **lst);

int		join_ast(t_btree **ast, t_btree **new_node);
int		gen_node(t_btree **ast);

/*
 * Build AST
 *
*/

union	u_word
{
	char	*word;
	int		fd;
};

struct	s_redir
{
	t_flag	type;
	int		n;
	t_word	word;
	int		close;
};

union	u_astdata
{
	t_redir	redir;
	t_ld	*token;
	t_list	*wordlist;
	char	**sstr;
	char	*str;
};

struct	s_astnode
{

	int			nest;
	int			full;
	int			pattern;
	t_type		type;
	t_astdata	data;
};

#endif
