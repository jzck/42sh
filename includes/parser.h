/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 15:58:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

/*
 * Parse POSIX grammar
 *
*/

typedef unsigned long long int 		t_sym;

#define	PROGRAM 			(1UL << 0)
#define COMPLETE_COMMANDS	(1UL << 1)
#define COMPLETE_COMMAND	(1UL << 2)
#define LIST				(1UL << 3)
#define AND_OR				(1UL << 4)
#define PIPELINE			(1UL << 5)
#define PIPE_SEQUENCE		(1UL << 6)
#define COMMAND				(1UL << 7)
#define COMPOUND_COMMAND	(1UL << 8)
#define SUBSHELL			(1UL << 9)
#define COMPOUND_LIST		(1UL << 10)
#define TERM				(1UL << 11)
#define FOR_CLAUSE			(1UL << 12)
#define NAME				(1UL << 13)
#define IN					(1UL << 14)
#define WORDLIST			(1UL << 15)
#define CASE_CLAUSE			(1UL << 16)
#define CASE_LIST_NS		(1UL << 17)
#define CASE_LIST			(1UL << 18)
#define CASE_ITEM_NS		(1UL << 19)
#define PATTERN				(1UL << 20)
#define IF_CLAUSE			(1UL << 21)
#define ELSE_PART			(1UL << 22)
#define WHILE_CLAUSE		(1UL << 23)
#define UNTIL_CLAUSE		(1UL << 24)
#define FUNCTION_DEFINITION	(1UL << 25)
#define FUNCTION_BODY		(1UL << 26)
#define FNAME				(1UL << 27)
#define BRACE_GROUP			(1UL << 28)
#define DO_GROUP			(1UL << 29)
#define SIMPLE_COMMAND		(1UL << 30)
#define CMD_NAME			(1UL << 31)
#define CMD_WORD			(1UL << 32)
#define CMD_PREFIX			(1UL << 33)
#define CMD_SUFFIX			(1UL << 34)
#define REDIRECT_LIST		(1UL << 35)
#define IO_REDIRECT			(1UL << 36)
#define IO_FILE				(1UL << 37)
#define FILENAME			(1UL << 38)
#define IO_HERE				(1UL << 39)
#define HERE_END			(1UL << 40)
#define NEWLINE_LIST		(1UL << 41)
#define LINEBREAK			(1UL << 42)
#define SEPARATOR_OP		(1UL << 43)
#define SEPARATOR			(1UL << 44)
#define SEQUENTIAL_SEP		(1UL << 45)

#define SYM_DLESS			(1UL << 46)
#define SYM_DGREAT			(1UL << 47)
#define SYM_GREATAND		(1UL << 48)
#define SYM_GREAT			(1UL << 49)
#define SYM_LESSAND			(1UL << 50)
#define SYM_LESS			(1UL << 51)


int		ft_parse(t_btree **ast, t_list **token);
int		produce_prim_sym(t_sym *new_sym, t_list **lst);

int		ft_read_stack(t_sym stack[], int size);
char	*read_state(t_sym current);

enum	e_parstate
{
	UNDEFINED,
	ERROR,
	SUCCESS,
};

typedef enum e_parstate t_parstate;

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
	t_type	type;
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
