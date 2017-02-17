/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/17 17:11:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
 * Parse POSIX grammar
 *
*/


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
	TK_SUBSHELL,
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
	TK_N_WORD,
	TK_Q_WORD,
	TK_DQ_WORD,
	TK_ASSIGNEMENT_WORD = 50,
	TK_BANG,	
	TK_NAME,
	TK_FOR,
	TK_IO_NUMBER,
	TK_DLESSDASH,
	TK_LESSGREAT,
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
	LOOP,
	FUNC,
	PIPE_SEMI_SEQUENCE,
	PATTERN_CASE,
	CMD_SUPERIOR,
	AND_OR_MAJOR,
	AND_OR_MINOR,
	ALL = 200,
};

typedef int		t_sym;

# define MATCH_STACK(x, y)		(x == y || y == ALL)

typedef int  t_parstate;

struct	s_aggrematch
{
	t_sym 	top;
	t_sym 	under;
	t_sym 	new_sym;
	int	erase_sym;
};

typedef struct s_aggrematch t_aggrematch;

extern t_aggrematch g_aggrematch[];

struct	s_prodmatch
{
	t_type	token;
	t_sym	stack;
	t_sym	new_sym;
};

typedef struct s_prodmatch t_prodmatch;

extern t_prodmatch g_prodmatch[];

struct	s_stackmatch
{
	t_sym top;
	t_sym under;
};

typedef struct s_stackmatch	t_stackmatch;

extern t_stackmatch g_stackmatch[];

int		ft_parse2(t_btree **ast, t_list **token);

int		ft_parse(t_btree **ast, t_list **token);
int		produce_sym(t_sym stack, t_sym *new_sym, t_list **lst);
int		eval_sym(t_sym stack, t_sym new_sym);
int		aggregate_sym(t_sym **stack, t_sym *new_sym, t_parstate *state);

int		push_stack(t_sym *stack, t_sym new_sym);
int		pop_stack(t_sym **stack, t_sym erase_sym);

int		error_syntax(t_list **token);

int		ft_read_stack(t_sym *stack); 
char		*read_state(t_sym current);

#define UNDEFINED	(1 << 0)
#define ERROR		(1 << 1)
#define SUCCESS		(1 << 2)

/*
 * Build AST - rewriting
 *
*/

struct	s_treematch
{
	t_type	type;
	int	(*add)(t_btree **ast, t_list **lst);
};

typedef struct s_treematch	t_treematch;

extern t_treematch g_treematch[];

int		build_tree(t_btree **ast, t_list **lst);

int		add_sep(t_btree **ast, t_list **lst);
int		add_cmd(t_btree **ast, t_list **lst);
int		add_file(t_btree **ast, t_list **lst);
int		isdir(t_btree **ast);

int		join_ast(t_btree **ast, t_btree **new_node);
int		gen_node(t_btree **ast);

/*
 * Build AST
 * 
*/

typedef struct s_parser		t_parser;
typedef struct	s_ld		t_ld;
typedef struct s_astnode	t_astnode;
typedef struct s_redir		t_redir;
typedef union u_astdata		t_astdata;
typedef union u_word		t_word;
typedef long long		t_type;

struct	s_parser
{
	t_type		type;
	int		(*f)(t_btree **ast,
			t_list **start, t_list **token);
};

union	u_word
{
	char	*word;
	int		fd;
};

struct	s_redir
{
	int		n;
	int		close;
	t_word	word;
};

union	u_astdata
{
	t_redir	redir;
	t_ld	*token;
	char	**sstr;
	char	*str;
};

struct	s_astnode
{
	t_type		type;
	t_astdata	data;
};

extern t_parser		g_parser[];

int		parse(t_btree **ast, t_list **token);

int		get_instruction(t_list **lst);
int		get_sub_instruction(t_btree **ast, t_list **start, t_list **lst);

int		parse_newline(t_btree **ast, t_list **start, t_list **lst);
int		parse_separator(t_btree **ast, t_list **start, t_list **lst);
int		parse_less(t_btree **ast, t_list **start, t_list **lst);
int		parse_great(t_btree **ast, t_list **start, t_list **lst);
int		parse_dless(t_btree **ast, t_list **start, t_list **lst);
int		parse_dgreat(t_btree **ast, t_list **start, t_list **lst);
int		parse_lessand(t_btree **ast, t_list **start, t_list **lst);
int		parse_greatand(t_btree **ast, t_list **start, t_list **lst);
int		parse_word(t_btree **ast, t_list **start, t_list **lst);
int		parse_subshell(t_btree **ast, t_list **start, t_list **lst);
int		parse_newline(t_btree **ast, t_list **start, t_list **lst);
int		parse_while(t_btree **ast, t_list **start, t_list **lst);
int		parse_if(t_btree **ast, t_list **start, t_list **lst);
int		parse_do(t_btree **ast, t_list **start, t_list **lst);
int		parse_done(t_btree **ast, t_list **start, t_list **lst);
int		parse_elif(t_btree **ast, t_list **start, t_list **lst);
int		parse_else(t_btree **ast, t_list **start, t_list **lst);

int		delete_newline(t_list **start, t_list **lst);
int		parse_head(t_btree **ast, t_btree **new_ast, t_list **start, t_list **lst);

#endif
